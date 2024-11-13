#include <iostream>
#include <fstream>
#include <stdexcept>

// Forward declaration of classes
class fileRA;
class fileRADescriptor;

// Class to manage reading/writing a specific position in a file
class fileRADescriptor 
{
private:
    std::fstream& file;        // Reference to the file stream (opened in fileRA)
    unsigned int position;      // Position in the file

public:
    // Constructor sets up the position in the file for reading/writing
    fileRADescriptor(std::fstream& file, unsigned int pos) : file(file), position(pos) 
    {
        file.seekg(position, std::ios::beg);  // Move get pointer to the position
        file.seekp(position, std::ios::beg);  // Move put pointer to the position
    }

    // Conversion operator to read a character at the given position
    operator char() const
     {
        file.seekg(position, std::ios::beg);  // Move get pointer to the position
        char c;
        file.get(c);                          // Retrieve the character at position
        return c;
    }

    // Assignment operator to write a character at the given position
    fileRADescriptor& operator=(char c) 
    {
        file.seekp(position, std::ios::beg);  // Move put pointer to the position
        file.put(c);                          // Write character at position
        return *this;
    }
};

// Class to handle random access to file content
class fileRA 
{
private:
    std::fstream file;          // File stream object
    unsigned int size;          // Size of the file in bytes

public:
    // Constructor to open the file in binary read/write mode and determine file size
    fileRA(const std::string& filename)
     {
        file.open(filename, std::ios::in | std::ios::out | std::ios::binary); // Open file in binary mode
        if (!file) 
        {
            throw std::runtime_error("Could not open file.");  // Throw an error if file fails to open
        }
        file.seekg(0, std::ios::end);  // Move to the end to determine size
        size = file.tellg();           // Get the size of the file
        file.seekg(0, std::ios::beg);  // Reset to the beginning
    }

    // Destructor to close the file if it's open
    ~fileRA()
     {
        if (file.is_open()) 
        {
            file.close();  // Close the file to release resources
        }
    }

    // Getter function to return the size of the file
    unsigned int get_size() const
     {
        return size;
    }

    // Overloaded subscript operator to access a specific position in the file
    fileRADescriptor operator[](unsigned int index) 
    {
        if (index >= size)
         {  // Check if index is within bounds
            throw std::out_of_range("Index out of range");
        }
        return fileRADescriptor(file, index);  // Return a descriptor for this position
    }
};

int main() 
{
    try {
        fileRA fobj("Test.txt");   // Create fileRA object for random file access

        fobj[4] = 'A';             // Set character at index 4 to 'A'
        
        // Loop to print each character in the file
        for (unsigned int i = 0; i < fobj.get_size(); i++)
         {
            std::cout << fobj[i];
         }
        std::cout << std::endl;

        char c = fobj[1];          // Retrieve character at index 1
        std::cout << "Char is = " << c << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Catch and display any exceptions
    }

    return 0;
}
