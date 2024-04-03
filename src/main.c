#include <stdio.h>
#include <stdlib.h>

typedef void (*Callback)(void);
typedef void (*Wrapper)(void);

void event_loop_add(Callback cb);
void event_loop_add(Callback cb) {
    cb();
}

void cortex_run_handler(Wrapper wrp);
void cortex_run_handler(Wrapper wrp) {
    wrp();
}

void hello() {
    printf("Hello ");
}

void world() {
    printf("World\n");
}

void wrp_hello() {
    hello();
}

void wrp_world() {
    world();
}

int cortex_main_loop() {

    // add a new handler on EV
    cortex_run_handler(wrp_hello);
    cortex_run_handler(wrp_world);

    return EXIT_SUCCESS;
}

int main(void) {
    return cortex_main_loop();
}