#include "session_fixture.h"

#include <libssh2.h>

#include <stdio.h>

/* configured in Dockerfile */
static const char *USERNAME = "libssh2";
static const char *PASSWORD = "my test password";

static void kbd_callback(const char *name, int name_len,
                         const char *instruct, int instruct_len,
                         int num_prompts,
                         const LIBSSH2_USERAUTH_KBDINT_PROMPT *prompts,
                         LIBSSH2_USERAUTH_KBDINT_RESPONSE *responses,
                         void **abstract)
{
    int i;
    (void)abstract;

    fprintf(stdout, "Kb-int name: %.*s\n", name_len, name);
    fprintf(stdout, "Kb-int instruction: %.*s\n", instruct_len, instruct);
    for(i = 0; i < num_prompts; ++i) {
        fprintf(stdout, "Kb-int prompt %d: %.*s\n", i,
                (int)prompts[i].length, prompts[i].text);
    }

    if(num_prompts == 1) {
        responses[0].text = strdup(PASSWORD);
        responses[0].length = strlen(PASSWORD);
    }
}

int test(LIBSSH2_SESSION *session)
{
    int rc;

    const char *userauth_list =
        libssh2_userauth_list(session, USERNAME, strlen(USERNAME));
    if(userauth_list == NULL) {
        print_last_session_error("libssh2_userauth_list");
        return 1;
    }

    if(strstr(userauth_list, "keyboard-interactive") == NULL) {
        fprintf(stderr,
                "'keyboard-interactive' was expected in userauth list: %s\n",
                userauth_list);
        return 1;
    }

    rc = libssh2_userauth_keyboard_interactive_ex(
        session, USERNAME, strlen(USERNAME), kbd_callback);
    if(rc != 0) {
        print_last_session_error("libssh2_userauth_keyboard_interactive_ex");
        return 1;
    }

    return 0;
}
