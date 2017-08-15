//
//  main.cpp
//  Inbox
//
//  Created by Justin Thompson on 8/15/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#include <iostream>
#include "Inbox.hpp"

using namespace std;

Inbox In("justinthompson593@gmail.com");

int main(int argc, const char * argv[]) {

	cout << "sup worl?" << endl;
	
	In.message();

	return 0;
}
