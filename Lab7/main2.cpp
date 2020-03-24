#include <iostream> // cout, endl
#include <stdio.h> // printf
#include <math.h> // pow
#include <iomanip> // hex, dec

size_t hash(size_t); // Hashes a given integer based off the multiplication method
void displayHash(size_t); // Takes a size_t and displays the hash in hexadecimal
size_t hashString1(std::string); // First function to hash a string
size_t hashString2(std::string); // Second function to hash a string

int main() {

	std::cout << "Starting tests of integer hash function..." << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "Integer: " << 5 << std::endl;
	displayHash(hash(5));
	std::cout << std::dec << "Integer: " << 17 << std::endl;
	displayHash(hash(17));
	std::cout << std::dec << "Integer: " << 1001 << std::endl;
	displayHash(hash(1001));
	std::cout << std::dec << "Integer: " << 50000 << std::endl;
	displayHash(hash(50000));
	std::cout << "Proving the hash works on the same number..." << std::endl;
	std::cout << std::dec << "Integer: " << 5 << std::endl;
	displayHash(hash(5));
	std::cout << "Matches the first test!" << std::endl;
	std::cout << "==========================================" << std::endl;

	std::cout << "Starting tests of string hash function 1..." << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "String: " << "The cow jumped over the moon" << std::endl;
	displayHash(hashString1("The cow jumped over the moon"));
	std::cout << "String: " << "Hi" << std::endl;
	displayHash(hashString1("Hi"));
	std::cout << "String: " << "Woah, just take it easy man" << std::endl;
	displayHash(hashString1("Woah, just take it easy man"));
	std::cout << "Proving the hash works on the same string..." << std::endl;
	std::cout << "String: " << "The cow jumped over the moon" << std::endl;
	displayHash(hashString1("The cow jumped over the moon"));	
	std::cout << "==========================================" << std::endl;

	std::cout << "Starting tests of string hash function 2..." << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "String: " << "How are you?" << std::endl;
	displayHash(hashString2("How are you?"));
	std::cout << "String: " << "Ughh, we are really out of school for the semester. This sucks." << std::endl;
	displayHash(hashString2("Ughh, we are really out of school for the semester. This sucks."));
	std::cout << "String: " << "Happy Birthday" << std::endl;
	displayHash(hashString2("Happy Birthday"));
	std::cout << "Proving the hash works on the same string..." << std::endl;
	std::cout << "String: " << "Happy Birthday" << std::endl;
	displayHash(hashString2("Happy Birthday"));
	std::cout << "==========================================" << std::endl;

	std::cout << "Showing that the two different string hash functions produce different results..." << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "String: " << "Why are you so rude?" << std::endl;
	std::cout << "HashString1:" << std::endl;
	displayHash(hashString1("Why are you so rude?"));
	std::cout << "HashString2:" << std::endl;
	displayHash(hashString2("Why are you so rude?"));
	std::cout << "==========================================" << std::endl;

	return 0;
} 

/*
 * hash Function:
 * Hashes a function based on a given integer using the multiplication method
 */
size_t hash(size_t num) {
	size_t W = pow(2, 64);
	size_t a = 7919;
	return (a * num % W) / pow(2, 64 - 53);
	// return (a * num % W) >> (64 - 53);
}

/*
 * hashString1 Function:
 * Takes a string and returns a size_t hash as a result
 */
size_t hashString1(std::string hashMe) {
	size_t sum = 0;
	for (int i = 0; i < hashMe.length(); i++) {
		sum += (int)hashMe[i];
	}
	return sum % 531;
}

/*
 * hashString2 Function:
 * Takes a string and returns a size_t hash as a result in a different way
 */
size_t hashString2(std::string hashMe) {
	size_t odd = 151;
	unsigned long long newHash = 0;
	for (int i = 0; i < hashMe.length(); i++) {
		newHash = (newHash * odd) + hashMe[i];
	}
	return newHash % 531;
}

/*
 * displayHash Function:
 * Function that turns the hash into a hexadecimal to be able to be displayed on screen
 */
void displayHash(size_t num) {
	std::cout << "Hash is " << std::hex << num << std::endl;
}
