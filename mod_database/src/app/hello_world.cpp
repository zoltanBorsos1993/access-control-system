#include <iostream>
#include <czmq.h>

using namespace std;

int main (void)
{
    zsock_t *push = zsock_new_push ("inproc://example");
    zsock_t *pull = zsock_new_pull ("inproc://example");
    zstr_send (push, "Hello, World, I am mod_database talking to you via ZMQ!");

    char *string = zstr_recv (pull);
    puts (string);
    zstr_free (&string);

    zsock_destroy (&pull);
    zsock_destroy (&push);
    return 0;
}
