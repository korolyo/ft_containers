//
// Created by Atom Collin on 8/20/22.
//

#ifndef FT_CONTAINERS_SANDBOX_H
#define FT_CONTAINERS_SANDBOX_H


struct String {
    explicit String(char const *s);
};

struct Number {};

struct BigInt : Number
{
    BigInt(int);
};

int main(void) {
    int a = 27;
    int const b = 412;
    int * pa = &a;

    int const c = a;
    int d = b;
    int const *p1 = pa;
    int * const *p2 = &pa;
    int const ** p3 = &pa;


}
#endif //FT_CONTAINERS_SANDBOX_H
