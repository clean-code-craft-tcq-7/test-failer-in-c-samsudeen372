#include <stdio.h>
#include <assert.h>

char size(int cms) {
    if(cms < 38) {
        return 'S';
    } else if(cms > 38 && cms < 42) {
        return 'M';
    } else if(cms > 42) {
        return 'L';
    }
}

void main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    printf("All is well (maybe!)\n");
}
