//You have been given the Writer class, which can write data on the screen, 
//in a file or in memory, in general, it doesn't matter where. 
//This class has a virtual function Write, which accepts a pointer to the input bytes of memory and their number. 
//The function tries to write these bytes to the right place. 

//However, the output operation has overhead, and frequent Write calls with small data sizes can slow down the program.
//You need to write inherited class BufferedWriter that would perform buffered output. 
//The constructor of this class must take a parameter of type size_t - the size of the buffer.
//Overriden Write function must first write to the internal buffer, 
//and only when it is full, call Write of the base class with the data of this buffer. At the end of the usage of the class, 
//the remaining data in the buffer must also be written through the call to the base class's Write function.

//Class from "writer.h"
//сlass Writer {
//public: 
//funtction for output (not given by task)
//    virtual void Write(const char * data, size_t len) {}
//};

#include "writer.h"
#include <cstddef>
#include <stdio.h>
#include <string.h>
class BufferedWriter: public Writer
{
protected:
    size_t size;
    size_t nsize;
    char * buff = nullptr;
public:
    BufferedWriter(size_t h)
    {
        size = h;
        nsize = 0;
        buff = new char[h];
    }
    void Write(const char * data, size_t length) override
    {
        size_t i;
        for (i = 0; i < length; i++)
        {
            if (nsize == size)
            {
                Writer::Write(buff, nsize);
                nsize = 0;
            }
            buff[nsize] = data[i];
            nsize++;
        }
    }
    ~BufferedWriter()
    {
        Writer::Write(buff, nsize);
        delete[] buff;   
    }
};
