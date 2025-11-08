#include "Harl.hpp"

int main() {
    Harl filter;

    filter.complain("INFO");
    filter.complain("DEBUG");
    filter.complain("WARNING");
    filter.complain("ERROR");
}