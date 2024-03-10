#include <stdio.h>
#include <stdlib.h>
// You need to print numbers from 1 to 200 in a new line.
// But for every multiple of 5, print "Foo", for every multiple of 7, print "Bar",
// and for every multiple of both 5 and 7, print "FooBar" instead of the number.
int main() {
    for (int i = 1; i <= 200; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            printf("FooBar\n");
        } else if (i % 5 == 0) {
            printf("Foo\n");
        } else if (i % 7 == 0) {
            printf("Bar\n");
        } else {
            printf("%d, ", i);
        }
    }
    return 0;
}
