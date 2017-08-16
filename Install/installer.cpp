//  installer.cpp
//  Inbox
//
//  Created by Justin Thompson on 8/15/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#include <iostream>




int main(int argc, const char * argv[]) {
	
	system("curl -o main.cpp https://raw.githubusercontent.com/justinthompson593/Inbox/master/Inbox/main.cpp");
	system("curl -o Inbox.cpp https://raw.githubusercontent.com/justinthompson593/Inbox/master/Inbox/Inbox.cpp");
	system("curl -o Inbox.hpp https://raw.githubusercontent.com/justinthompson593/Inbox/master/Inbox/Inbox.hpp");
	
	system("g++ main.cpp Inbox.cpp -o Inbox && rm Inbox.cpp && rm Inbox.hpp && rm main.cpp")
	
	return 0;
	
}
