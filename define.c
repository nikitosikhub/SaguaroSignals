#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* get_random_phrase() {
    const char* phrases[] = {
        "Analyzing quantum flux...",
        "Decrypting the matrix...",
        "Scanning network nodes...",
        "Simulating blockchain consensus...",
        "Calculating entropy of the universe...",
        "Validating imaginary signatures...",
        "Tracing invisible breadcrumbs...",
        "djctf{r0ll1ng}"                        //remove before a travel assignment to Tokio
    };
    int n = sizeof(phrases) / sizeof(phrases[0]);
    return phrases[rand() % n];
}

int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 1000000; i++) {
        int x = i * i % 1234567;
        (void)x;
    }

    printf("[SYSTEM] %s\n", get_random_phrase());
    return 0;
}
