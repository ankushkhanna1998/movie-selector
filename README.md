# Movie Selector

This is a console application written in C++ (initially in ISO C++17) which helps select a random movie to watch from the available ones in the given directories.

Basically, not just movies, it can be used to select anything from anywhere. One just needs to write a valid [Regular Expression](https://en.wikipedia.org/wiki/Regular_expression) to match the desired files in the given directories, and then among the matched ones, this application provides a random file name.

### How can one make it work?

One just needs to add the search path(s) as mentioned in the code (where we have the files to select from), and a [Regular Expression](https://en.wikipedia.org/wiki/Regular_expression) to match desired file names (examples are mentioned as comments).

Then, one needs to compile the code. The most simple way to do so is:

```bash
mkdir --parents build/
g++ -std=c++17 -o build/movie movie.cpp
```

Running it is simple then:

```bash
./build/movie
```

You can use the compile options of your choice, just make sure you compile the source with C++17 (or higher) enabled (`-std=c++17`, `-std=gnu++17` or higher), as this code makes use of the `std::filesystem` API which came out with the ISO C++17 standard.

### Some History (in case you're interested)

A few years back (in 2017), I accumulated a lot of movies in my movie collection. It got bloated so much, that it was always hard for me to just pick one to watch! So, I wrote a very simple code in C++ (the source name was `movie.cpp`) back then, which just gave me a random movie name among the ones which existed in the given search paths. It did work out well enough for me, I never had any problems selecting stuff.

Some time back (in 2020), I accidentally removed this source (along with the executable), and sadly, I didn't have any backup for it! This is when I realized how heavily I relied on it! 😥️

So, I definitely wanted to write it back again, and in a better way, in terms of design and coding, as I believe I had a lot more knowledge compared to what I had at that time. Plus, this time C++ also had become a lot more advanced than what it used to be. So this is my new implementation, which, in a sense, is lot more generic and general purpose.

Though it is very general purpose, still the the only reason why I named it to `movie.cpp`, and the repository as `movie-selector`, is to pay my respects to the original source. 🙇🏻‍♂️️

And, by the way, this is how I compiled it for myself:

```bash
g++ -no-pie -fno-pie -fsanitize=address -fno-omit-frame-pointer -fno-common -pthread -Wall -Wextra -Wpedantic -O3 -ggdb3 -std=c++23 -o build/movie movie.cpp
```
