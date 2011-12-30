#include "FImage.h"

using namespace FImage;

int main(int argc, char **argv) {
    Var x, y, z;
    Func f, g;

    g(x, y) = x*y;
    f(x, y) = g(x-1, y) + g(x+1, y);


    g.chunk(y);
    f.parallel(y);

    Image<int> im = f.realize(8, 8);

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (im(x, y) != (x-1)*y + (x+1)*y) {
                printf("im(%d, %d) = %d\n", x, y, im(x, y));
                return -1;
          }
        }
    }
    
    printf("Success!");
    return 0;
}