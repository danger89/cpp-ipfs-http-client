/* Copyright (c) 2016-2016, Vasil Dimov

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include <iostream>
#include <stdexcept>
#include <string>

#include <ipfs/client.h>
#include "utils.h"

int main(int, char**) {
  try {
    ipfs::Client client("localhost", 5001);

    /** [ipfs::Client::ObjectNew] */
    std::string object_id;
    client.ObjectNew(&object_id);
    std::cout << "New object id: " << object_id << std::endl;
    /* An example output:
    New object id: QmdfTbBqBPQ7VNxZEYEj14VmRuZBkqFbiwReogJgS1zR1n
    */
    /** [ipfs::Client::ObjectNew] */

    /** [ipfs::Client::ObjectStat] */
    ipfs::Json stat;
    client.ObjectStat(
        "QmYwAPJzv5CZsnA625s3Xf2nemtYgPpHdWEz79ojWnPbdG",
        &stat);
    std::cout << "Object data size: " << stat["DataSize"] << std::endl;
    /* An example output:
    Object data size: 2
    */
    /** [ipfs::Client::ObjectStat] */
    check_if_properties_exist("client.ObjectStat()", stat,
                              {"BlockSize", "CumulativeSize", "DataSize",
                               "Hash", "LinksSize", "NumLinks"});
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}