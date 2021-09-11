#include <iostream>


void palindrome (char x[], int left, int right)
{
	while (left < right) {
		if (x[left] == x[right]){
			left++;
			right--;
		}
		else
		{	printf("not a palindrome"); 
			return;
		}
	}
	printf("it is palindrome");
}



int main()
{
	// std::string x= "abcba";
	char x[] = "abcbae";
	// int len = x.length();
	int len = sizeof(x) / sizeof(x[0]);
	palindrome(x, 0, len-2);
	return 0;
}
