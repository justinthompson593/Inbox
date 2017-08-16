//
//  Inbox.hpp
//  Inbox
//
//  Created by Justin Thompson on 8/15/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#ifndef Inbox_hpp
#define Inbox_hpp

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class Inbox {
	
	string userEmail;
	
	bool checkContactsForEmailAddress(string email);
	
public:
	
	Inbox(string userEmail);
	
	void pushChanges();
	void message();
	void getMessages();
	
};


#endif /* Inbox_hpp */
