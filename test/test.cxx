
#include <bdd.hpp>
#include <debug_bdd.hpp>


int main() {

    BDD bdds(1000, 2, 10);

    int z1 = bdds._and_(2, 3);
    int z2 = bdds._not_(z1);

    // cout << "--------------------\n";
    // print_bdd(bdds, 2);
    // cout << "--------------------\n";
    // print_bdd(bdds, 3);
    // cout << "--------------------\n";
    // print_bdd(bdds, z1);
    // cout << "--------------------\n";
    print_bdd(bdds, z2);
    return 0;
}