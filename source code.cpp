#include<iostream>
#include <ctgmath>
using namespace std;
void download(int opt)
{
	string adr,s="youtube-dl ";
	printf("Enter Video URL:");
	cin>>adr;
	if (opt == 1)
	{
		string qlt;
		printf("Choose quanlity(4K,1080p,720p or other format code):");
		cin >> qlt;
		if (qlt == "4K" or qlt == "4k")	s += "-f 315+140 ";
		else if (qlt == "1080p")	s += "-f 299+140 ";
		else if (qlt == "720p")	s += "-f 298+140 ";
		else s += "-f " + qlt;
	}
	else if (opt == 2)	s += "-f 299+140 ";
	else if (opt == 3 or opt == 4)
	{
		string port,qlt;
		printf("Make sure your proxy software is running\n"
			"Enter your proxy port (enter 0 to skip):");
		cin >> port;

		printf("Choose quanlity(4K,1080p,720p or other format code):");
		cin >> qlt;
		if (qlt == "4K")	s += "-f 315+140 ";
		else if (qlt == "1080p")	s += "-f 299+140 ";
		else if (qlt == "720p")	s += "-f 298+140 ";
		else s += "-f " + qlt;

		s += opt == 3 ? "--proxy 127.0.0.1:": "--proxy socks5://127.0.0.1:";
		s += port == "0" ? "10808 " : port + " ";
	}
	s += adr;
cout << "---Command:" << s << endl;
	system(s.c_str());
}
void menu()
{
	string opt;
	printf(
		"------------Youtube-dl Assistant------------\n"
		"0.Download video directly in default\n"
		"1.Download video directly\n"
		"2.Download video directly in 1080p(if support)\n"
		"3.Download video through proxy\n"
		"4.Download video through socks5 proxy\n"
		"5.Change setting\n"
		"6.Exit\n"
	);

	scan_opt:
	printf("\nEnter the number to continue - ");
	cin >> opt;
	if (opt == "6")	return;
	else if (opt <= "5" and opt >= "0") download(stoi(opt));
	else
	{
		printf("Invalid number.");
		goto scan_opt;
	}

	printf("\n\n\n");
	menu();
}
int main()
{
	menu();
	return 0;
}
