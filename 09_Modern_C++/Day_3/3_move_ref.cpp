#include <string>

int main()
{
    /* move is better than copy
       C++ : default is copy, use std::move() if needed.
    */

    std::string s1 = "to be or not to be";
    std::string s2 = s1;            /* copy */
    std::string s3 = std::move(s1); /* move */

    /* What if move is default? */
    /* It is Rust below. */
    let s1 = String::from("to be or not to be");
    let s2 = String::from("to be or not to be");
    
    let s3 = s1;            /* move! */
    let s4 = s1.clone();    /* copy! */
}