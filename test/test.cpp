// #include "catch/catch_amalgamated.hpp"
// #include "../src/AVL.h"
// #include "../src/parsing.h"
// #include "../src/main.cpp"
// #include <iostream>

// // uncomment and replace the following with your own headers
// // #include "AVL.h"

// using namespace std;

// // the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
// TEST_CASE("Example Test Name - Change me!", "[flag]"){
// 	// instantiate any class members that you need to test here
// 	int one = 1;

// 	// anything that evaluates to false in a REQUIRE block will result in a failing test 
// 	REQUIRE(one == 0); // fix me!

// 	// all REQUIRE blocks must evaluate to true for the whole test to pass
// 	REQUIRE(false); // also fix me!
// }

// TEST_CASE("Test 2", "[flag]"){
// 	// you can also use "sections" to share setup code between tests, for example:
// 	int one = 1;

// 	SECTION("num is 2") {
// 		int num = one + 1;
// 		REQUIRE(num == 2);
// 	};

// 	SECTION("num is 3") {
// 		int num = one + 2;
// 		REQUIRE(num == 3);
// 	};

// 	// each section runs the setup code independently to ensure that they don't affect each other
// }

// // you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// // the provided test from the template is below.

// TEST_CASE("Incorrect Commands", "[flag]") {
	
// 		AVL tree;
// 		parser("insert \"J@y Maisuria\" 00000001", tree);
// 		parser("insert \"Jay Maisuria\" 00000000", tree);	
// 		parser("insert \"Jay Maisuria\" 0000o000", tree);
// 		parser("insert \"br03$\" 00000002", tree);		
// 		parser("insert \"Hello\" 0000000011", tree);	
// 		parser("reeemove Jay Maisuria", tree);	
// 		parser("printIinorder Jay Maisuria", tree);		
	
// }

// TEST_CASE("Edge Cases", "[flag]") {
	
// 		AVL tree;
// 		parser("insert \"Jay Maisuria\" 0000000", tree);	
// 		parser("insert \"Jay Maisuria\" 0000o000", tree);
// 		parser("removeInorder 7", tree);
// 		parser("remove Hay Maisuria", tree);		
// 		parser("remove 11111111", tree);

// }

// TEST_CASE("Four Rotations", "[flag]") {
	
// 		AVL tree;
// 		parser("insert \"Jay Maisuria\" 00000001", tree);	
// 		parser("insert \"Jay Maisuria\" 00000002", tree);
// 		parser("insert \"Jay Maisuria\" 00000003", tree);

// 		parser("insert \"Jay Maisuria\" 00000007", tree);	
// 		parser("insert \"Jay Maisuria\" 00000006", tree);
// 		parser("insert \"Jay Maisuria\" 00000005", tree);

// 		parser("insert \"Jay Maisuria\" 00000015", tree);	
// 		parser("insert \"Jay Maisuria\" 00000013", tree);
// 		parser("insert \"Jay Maisuria\" 00000014", tree);

// 		parser("insert \"Jay Maisuria\" 00000020", tree);	
// 		parser("insert \"Jay Maisuria\" 00000022", tree);
// 		parser("insert \"Jay Maisuria\" 00000021", tree);

// }

// TEST_CASE("Remove 0, 1, 2 children", "[flag]") {
	
// 		AVL tree;
// 		parser("insert \"Jay Maisuria\" 00000001", tree);	
// 		parser("insert \"Jay Maisuria\" 00000002", tree);
// 		parser("insert \"Jay Maisuria\" 00000003", tree);

// 		parser("insert \"Jay Maisuria\" 00000007", tree);	
// 		parser("insert \"Jay Maisuria\" 00000006", tree);
// 		parser("insert \"Jay Maisuria\" 00000005", tree);

// 		parser("insert \"Jay Maisuria\" 00000015", tree);	
// 		parser("insert \"Jay Maisuria\" 00000013", tree);
// 		parser("insert \"Jay Maisuria\" 00000014", tree);

// 		parser("remove \"Jay Maisuria\" 00000003", tree);
// 		parser("remove \"Jay Maisuria\" 00000007", tree);
// 		parser("remove \"Jay Maisuria\" 00000015", tree);	
		

// }

// TEST_CASE("100 Insertions", "[flag]") {
	
// 		AVL tree;

// 		for (int i = 10000000; i < 10000100; i++) {

// 			string id = to_string(i);
// 			string command = "insert \"Student\" ";
// 			parser(	command.append(id), tree);

// 		}
		
// 		for (int i = 10000000; i < 10000100; i++) {
		
// 			string id = to_string(i);
// 			string command = "remove ";
// 			parser(command.append(id), tree);

// 		}

// }