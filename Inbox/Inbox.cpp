//
//  Inbox.cpp
//  Inbox
//
//  Created by Justin Thompson on 8/15/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#include "Inbox.hpp"

Inbox::Inbox(string email){
	userEmail = email;
}


void Inbox::pushChanges(){
	system("git add -A");
	system("echo \"Enter a commit message in quotes:\"");
	system("read usrIn");
	system("git commit -m \"$usrIn\"");
	system("git push -u origin master");
}


bool Inbox::checkContactsForEmailAddress(string email){
	ifstream contax("contacts.txt");
	if(contax.fail()){
		cout << "ERROR: Inbox::checkEmails(" << email << "):  Cannot find contacts.txt" << endl;
		return false;
	}
	else{
		string line;
		while( getline(contax, line) ){
			size_t idx = line.find(" ");
			string thisEmail = line.substr(0,idx);
			if( thisEmail.compare(email) == 0 ){
				return true;
			}
		}
	}
	
	return false;
}



void Inbox::message(){
	
	// Get senders's email from git
	string sndEmail;
	system("echo `git config user.email` > tempEmail");
	
	ifstream ifs("tempEmail");
	if(!ifs.fail()){
		getline(ifs, sndEmail);
		ifs.close();
	}
	
	system("rm tempEmail");
	
	
	system("clear");
	
	cout << "\n\n\n\n\n\n\nPrepare to write email\n\n\tTo: " << userEmail << "\n\tFrom: " << sndEmail << endl;
	
	system("sleep 2");
	system("clear");
	//	nano msg
	system("nano tmpMsg");
	
	char toSys[2048];
	sprintf(toSys, "gpg -e -a -u %s -r %s tmpMsg && rm tmpMsg", sndEmail.c_str() , userEmail.c_str());
	system(toSys);
	
	size_t idx = sndEmail.find("@");
	string emailPref = sndEmail.substr(0,idx);
	string emailSuff = sndEmail.substr(idx+1);
	
	cout << "email from " << emailPref << "@" << emailSuff << endl;
	
	//	system("thisDate=$(date '+%Y/%m/%d_%H:%M:%S')");
	sprintf(toSys, "mv tmpMsg.asc %s_$(date '+%sY-%sm-%sd_%sH:%sM:%sS').txt.asc", emailPref.c_str(), "%", "%", "%", "%", "%", "%");
	system(toSys);
	
	//
	//	sender="$1"
	//	outName=""
	//	for (( i=0; i<${#sender}; i++ )); do
	//	if [ "${sender:$i:1}" == "@" ]; then
	//	break
	//	else
	//	outName="$outName${sender:$i:1}"
	//	fi
	//	done
	//
	//
	//	dt=$(date '+%Y/%m/%d_%H:%M:%S')
	//	mv msg.asc "$outName_on_$dt.txt.asc"
	
}
