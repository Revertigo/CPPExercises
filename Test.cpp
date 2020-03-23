#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of v and w"){
    string text = "thanks to stack overflow";
    CHECK(find(text, "overflov") == string("overflow"));
    CHECK(find(text, "owerflow") == string("overflow"));
    CHECK(find(text, "owerflov") == string("overflow"));
    CHECK(find(text, "overflow") == string("overflow"));
}

TEST_CASE("Test replacement of p and b and f") {
    string text = "this is my preferable language";
    //b and f
    CHECK(find(text, "breberable") == string("preferable"));
    CHECK(find(text, "breberafle") == string("preferable"));
    CHECK(find(text, "breferable") == string("preferable"));
    CHECK(find(text, "breferafle") == string("preferable"));
    CHECK(find(text, "freberable") == string("preferable"));
    CHECK(find(text, "freberafle") == string("preferable"));
    CHECK(find(text, "freferable") == string("preferable"));
    CHECK(find(text, "freferafle") == string("preferable"));

    //b and p
    CHECK(find(text, "breberaple") == string("preferable"));
    CHECK(find(text, "breperable") == string("preferable"));
    CHECK(find(text, "breperaple") == string("preferable"));
    CHECK(find(text, "preberable") == string("preferable"));
    CHECK(find(text, "preberaple") == string("preferable"));
    CHECK(find(text, "preperable") == string("preferable"));
    CHECK(find(text, "preperaple") == string("preferable"));

    //p and f
    CHECK(find(text, "preperafle") == string("preferable"));
    CHECK(find(text, "preferaple") == string("preferable"));
    CHECK(find(text, "preferafle") == string("preferable"));
    CHECK(find(text, "freperaple") == string("preferable"));
    CHECK(find(text, "freperafle") == string("preferable"));
    CHECK(find(text, "freferaple") == string("preferable"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of g and j"){
    string text = "in the jungle the mighty xxx";
    CHECK(find(text, "gungle") == string("jungle"));
    CHECK(find(text, "junjle") == string("jungle"));
    CHECK(find(text, "gunjle") == string("jungle"));
    CHECK(find(text, "jungle") == string("jungle"));
}

TEST_CASE("Test replacement of c and k and q"){
    string text = "quick and dirty";//Whattt, yes this is how we program in here

    //q and k
    CHECK(find(text, "quiqq") == string("quick"));
    CHECK(find(text, "quiqk") == string("quick"));
    CHECK(find(text, "quikq") == string("quick"));
    CHECK(find(text, "quikk") == string("quick"));
    CHECK(find(text, "kuiqq") == string("quick"));
    CHECK(find(text, "kuiqk") == string("quick"));
    CHECK(find(text, "kuikq") == string("quick"));
    CHECK(find(text, "kuikk") == string("quick"));

    //q and c
    CHECK(find(text, "quiqc") == string("quick"));
    CHECK(find(text, "quicq") == string("quick"));
    CHECK(find(text, "quicc") == string("quick"));
    CHECK(find(text, "cuiqq") == string("quick"));
    CHECK(find(text, "cuiqc") == string("quick"));
    CHECK(find(text, "cuicq") == string("quick"));
    CHECK(find(text, "cuicc") == string("quick"));

    //c and k
    CHECK(find(text, "cuick") == string("quick"));
    CHECK(find(text, "cuikc") == string("quick"));
    CHECK(find(text, "cuikk") == string("quick"));
    CHECK(find(text, "kuicc") == string("quick"));
    CHECK(find(text, "kuick") == string("quick"));
    CHECK(find(text, "kuikc") == string("quick"));

    //q and k and c
    CHECK(find(text, "cuikq") == string("quick"));
    CHECK(find(text, "cuiqk") == string("quick"));
    CHECK(find(text, "kuicq") == string("quick"));
    CHECK(find(text, "kuiqc") == string("quick"));
    CHECK(find(text, "quikc") == string("quick"));
    CHECK(find(text, "quick") == string("quick"));
}

TEST_CASE("Test replacement of s and z"){
    string text = "seize everything you ever wanted";
    CHECK(find(text, "seise") == string("seize"));
    CHECK(find(text, "zeize") == string("seize"));
    CHECK(find(text, "zeise") == string("seize"));
    CHECK(find(text, "seize") == string("seize"));
}

TEST_CASE("Test replacement of d and t"){
    string text = "dont xxx yyy";
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "tond") == string("dont"));
}

TEST_CASE("Test replacement of o and u"){
    string text = "dont worry yyy";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "dunt") == string("dont"));
    CHECK(find(text, "wurry") == string("worry"));
}

TEST_CASE("Test replacement of i and y"){
    string text = "worry yyy happy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "happi") == string("happy"));
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "worri") == string("worry"));
}

TEST_CASE("Test passing nullptr parameters"){
    CHECK(find(nullptr, nullptr) == string(""));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    //00000
    CHECK(find(text, "happi") == string("Happi"));
    //00001
    CHECK(find(text, "happI") == string("Happi"));
    //00010
    CHECK(find(text, "hapPi") == string("Happi"));
    //00011
    CHECK(find(text, "hapPI") == string("Happi"));
    //00100
    CHECK(find(text, "haPpi") == string("Happi"));
    //00101
    CHECK(find(text, "haPpI") == string("Happi"));
    //00110
    CHECK(find(text, "haPPi") == string("Happi"));
    //00111
    CHECK(find(text, "haPPI") == string("Happi"));
    //01000
    CHECK(find(text, "hAppi") == string("Happi"));
    //01001
    CHECK(find(text, "hAppI") == string("Happi"));
    //01010
    CHECK(find(text, "hApPi") == string("Happi"));
    //01011
    CHECK(find(text, "hApPI") == string("Happi"));
    //01100
    CHECK(find(text, "hAPpi") == string("Happi"));
    //01101
    CHECK(find(text, "hAPpI") == string("Happi"));
    //01110
    CHECK(find(text, "hAPPi") == string("Happi"));
    //01111
    CHECK(find(text, "hAPPI") == string("Happi"));
    //10000
    CHECK(find(text, "Happi") == string("Happi"));
    //10001
    CHECK(find(text, "HappI") == string("Happi"));
    //10010
    CHECK(find(text, "HapPi") == string("Happi"));
    //10011
    CHECK(find(text, "HapPI") == string("Happi"));
    //10100
    CHECK(find(text, "HaPpi") == string("Happi"));
    //10101
    CHECK(find(text, "HaPpI") == string("Happi"));
    //10110
    CHECK(find(text, "HaPPi") == string("Happi"));
    //10111
    CHECK(find(text, "HaPPI") == string("Happi"));
    //11000
    CHECK(find(text, "HAppi") == string("Happi"));
    //11001
    CHECK(find(text, "HAppI") == string("Happi"));
    //11010
    CHECK(find(text, "HApPi") == string("Happi"));
    //11011
    CHECK(find(text, "HApPI") == string("Happi"));
    //11100
    CHECK(find(text, "HAPpi") == string("Happi"));
    //11101
    CHECK(find(text, "HAPpI") == string("Happi"));
    //11110
    CHECK(find(text, "HAPPi") == string("Happi"));
    //11111
    CHECK(find(text, "HAPPI") == string("Happi"));
}