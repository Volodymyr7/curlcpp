/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 - Giuseppe Persico
 * File - curl_reader.h
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __curlcpp__curl_reader__
#define __curlcpp__curl_reader__

#include <iostream>

using std::istream;

// Let's typedef this big boy to enhance code readability.
typedef size_t (*curlcpp_reader_type)(void *, size_t, size_t, void *);

namespace curl {
    /**
     * This class allows users to specify a stream from which libcurl can read
     * input.  The curl_easy class will set all the necessary options to make it
     * easy. You just have to specify your stream and your reader function.
     */
    class curl_reader {
    public:
        /**
         * The default constructor will use a default stream and a default
         * reader callback to perform the operations.
         */
        curl_reader();
        /**
         * This overloaded constructor allows users to specify a stream
         * from which to read, using the default reader callback.
         */
        curl_reader(istream &);
        /**
         * This overloaded constructor allows users to specify a reader
         * callback function used to specify how to write something on
         * the default stream (which is std::cin)
         */
        curl_reader(curlcpp_reader_type);
        /**
         * This overloaded constructor allows users to specify a custom
         * stream and a custom reader callback function.
         */
        curl_reader(istream &, curlcpp_reader_type);
        /**
         * Simple getter method that returns the stream specified in the
         * constructor.
         */
        istream *get_stream() const;
        /**
         * Simple getter method that returns the function specified (or not)
         * in the constructor.
         */
        curlcpp_reader_type get_function() const;
    protected:
        /**
         * Utility method used to validate the function pointer eventually
         * specified.
         */
        void set_reader_ptr(curlcpp_reader_type);
    private:
        curlcpp_reader_type _reader_ptr;
        istream *_stream_ptr;
    };
}

#endif /* defined(__curlcpp__curl_reader__) */
