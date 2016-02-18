#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


// Use these constants for your arrays.
const int MAX_ROWS   = 100;
const int MAX_WIDTH  = 100;


// Side of an airplane, port or starboard. These terms are more
// precise than "left" and "right," which vary depending on whether
// you're facing forward or backward.
enum Side { 
   NotStowed = -1,
   Port, 
   Starboard 
};

class Passenger;


// TODO: From here on, you need to implement all of the member functions and
// add all of the member variables.
// --------------------------------------------------------------------------

// Represents a carryon bag owned by a passenger.
// Each bag has a single owner.
class Bag {
public:
   // Owner is a pointer to a Passenger object. A bag is
   // initialized not "stowed," meaning that it hasn't been 
   // stored in an overhead bin.
   Bag(const Passenger* owner) { 
      assert(owner); 
   }

   const Passenger* owner() const { 
      return nullptr; 
   }

   // Return true if the bag is stowed.
   bool is_stowed() const { 
      return false; 
   }

   // Stow the bag at the given bin location. 
   void stow(Side side, int row) {
      assert(side != Side::NotStowed);
      assert(row >= 0); 
      assert(row < MAX_ROWS); 
   }

   // Getters for the stow location.
   Side side() const { return Side::NotStowed; }
   int row() const { return -1; }

private:
   // TODO add member variables here.
};

// Represents one passenger, who may or may not have one carryon bag.
class Passenger {
public:
   // Create a passenger. id is a unique number which must be
   // positive. row and seat designate a seat location, which each must
   // also be positive. The passenger is created with no bags.
   //   
   // Row and seat are a zero based indices.
   Passenger(int id, int row, int seat) {}

   // getters
   int id() const { return -1; }
   int row() const { return -1; }
   int seat() const { return -1; }

   // Create a bag and assign it to this passenger.
   void bring_carryon() {}

   // Returns nullptr if passenger has no bags.
   Bag* carryon() { return nullptr; }

private:
   // TODO add member variables here.
};


// Represents a model of airplane, use static arrays to store the Passengers and 
// their carryons.
class Airplane {
public:
   // Initialize an airplane with a given number of rows of seats, and
   // width (number of passengers per row). Each argument must be
   // positive.
   Airplane(int rows, int width) {
      assert(rows >= 0);
      assert(rows < MAX_ROWS);
      assert(width >=0 );
      assert(width < MAX_WIDTH);

      // TODO: code that initializes the Airplane to an empty state.
   }

   int rows() const { return -1; }
   int width() const { return -1; }
   
   /*
   Prints out the passenger seating in a table.
   Each column is separated by a single space.
   The first column is 3 characters wide and displays the row number.
   The following columns are 6 characters wide and display the Seat numbers.
   The first line has the title of the printout "Seats"
   The second line are the column titles "Row Seat 1 Seat 2 Seat 3 Seat 4 Seat N".
   Empty seats display '------'.

   This is what a printout for an airplane with 10 rows, 4 wide, 36 passengers
   looks like:

   Seats
   Row Seat 1 Seat 2 Seat 3 Seat 4 
     1      1      2      3      4 
     2      5      6      7      8 
     3      9     10     11     12 
     4     13     14     15     16 
     5     17     18     19     20 
     6     21     22     23     24 
     7     25     26     27     28 
     8     29     30     31     32 
     9     33     34     35     36 
    10 ------ ------ ------ ------ 

   Please follow these instructions to make yours look just like this, 
   it'll make grading a lot easier for me.
   */   
   void PrintSeats() const {}


   /* Follow similar rules to above, print out the overhead bin configuration:

      Overhead Bins
      Row Port Starboard
        1   27   32 
        2   30   17 
        3   22   19 
        4 [  ] [  ]
        5 [  ] [  ]
        6 [  ] [  ]
        7 [  ] [  ]
        8 [  ] [  ]
        9 [  ] [  ]
       10 [  ] [  ]
   */
   void PrintOverheadBins() const {}


   // Attempt to place a passenger's carryon bag in an overhead bin.
   // Returns true if successful (or the passenger had no bag), 
   // false if there was a problem sotwing a bag.
   //
   // If the passenger has a carryon, try to find a location for it using the following
   // algorithm:

   // Try row 1 port side; if full, 
   // try row 1 starboard side; if full, 
   // try row 2 port side; if full, 
   // try row 2 starboard side; if full, 
   // try row 3 port side; etc. 
   //
   // The bag is stored in the plane's bin 2D array and 
   // the carryon's stow() function is called to record where the bag is.  
   bool place_carryon(Passenger* p) {
      assert(p);

      // No spot found.
      return false; 
   }   

   // Seat the passenger at the correct row and seat. 
   bool seat_passenger(Passenger* p) {
      assert(p);
      assert(p->row() >= 0);
      assert(p->row() < rows());
      assert(p->seat() >= 0);
      assert(p->seat() < width());

      return false;
   }


private:
   // TODO add your member variables here.
};


// ---------------------------------------------------------------
// There shouldn't be a need to edit any of the code from here on.
// ---------------------------------------------------------------


// Exits if not enough arguments were passed in at the command line.
void checkArgs(int argc, char **argv) {
   if (argc != 5) {
      std::cerr << "usage: " << argv[0] << " <BAG CHANCE> <ROWS> <WIDTH> <PASSENGER COUNT>" << std::endl;
      exit(-1);
   }
}

// Turns the command line arguments into variables.  
// Displays an error message and exits if any of the varaibles are out of range.
void parseArgs(char** argv, int& bag_chance, int& rows, int& width, int& passenger_count) {
   bag_chance = atoi(argv[1]);
   if (bag_chance < 0) {
      std::cerr << "bag_chance must be >= 0" << std::endl;
      exit(-1);
   }
   
   rows = atoi(argv[2]);
   if (rows < 1 || rows >= MAX_ROWS) {
      std::cerr << "rows must be between 1 and " << (MAX_ROWS-1) << std::endl;
      exit(-1);
   }
   
   width = atoi(argv[3]);
   if (width < 1 || width >= MAX_WIDTH) {
      std::cerr << "width must be between 1 and " << (MAX_WIDTH-1) << std::endl;
      exit(-1);
   }

   passenger_count = atoi(argv[4]);
   if (passenger_count < 0) {
      std::cerr << "passenger count must be positive" << std::endl;
      exit(-1);
   }

   if (passenger_count > (rows * width)) {
      std::cerr << "There can't be more passengers (" << passenger_count << ") " 
                << "than total seats (" << (rows * width) << ")." << std::endl;
      exit(-1);      
   }
}


void outputArgs(int bag_chance, int rows, int width, int passenger_count) {
   std::cout 
      << "Airline simulation:\n"
      << "   bag chance  : 1 in " << bag_chance << "\n" 
      << "   rows        : " << rows << "\n"
      << "   width       : " << width << "\n"
      << "   passengers  : " << passenger_count << "\n"
      << "\n";
}


// This is a table of 100 pseudo random integers 
// in a distribution of 1-100.  This table is used
// instead of a random number generator to ensure
// that repeated runs on different systems will 
// have identical results. 
const size_t NUM_RAND = 100;
const int RAND_TABLE[NUM_RAND] = {
    15,     98,     70,     35,     81, 
    89,     67,     35,     43,     77, 
    41,      3,     41,     50,     15, 
    79,    100,     97,      4,     87, 
    57,     84,     58,     19,     27, 
     5,     84,     27,     62,     56, 
    87,      4,     45,     67,     33, 
    22,     54,     43,     17,     80, 
     7,     35,     16,     29,     92, 
     9,     92,     21,      3,     96, 
     7,     36,     91,      3,     13, 
    94,     81,     39,     20,     29, 
    18,     87,      1,     92,    100, 
    15,     35,     16,     17,     60, 
    87,      2,     72,     12,      9, 
    79,     34,     19,     66,     48, 
    98,     23,     22,     96,     83, 
    35,     35,     19,     93,     93, 
   100,    100,     15,     33,     53, 
    13,     35,     79,     80,     47, 
};


// Make a vector of Passengers, increase their id, row and seat by one.
// Randomly give the passengers bags.
std::vector<Passenger*> newPassengers(int passenger_count, int width, int bag_chance) {
   std::vector<Passenger*> passengers;
   for (int id=0, row=0, seat=0; id < passenger_count; ++id) {
      passengers.push_back(new Passenger(id+1, row, seat));

      // Randomly give passengers bags based on bag_chance.
      if (RAND_TABLE[id % NUM_RAND] % bag_chance == 0)
         passengers.back()->bring_carryon();

      seat++;

      // If we hit the end of the row, bump the row, reset the seat.
      if (seat == width) {
         row++;
         seat = 0;
      }      
   }
   return passengers;
}


// Shuffle the passengers so that they board in a random order.
// Use the table of random values so that everyone will get the exact same values.
void shufflePassengers(std::vector<Passenger*>& passengers){
   for (int i = 0; i < passengers.size(); ++i) {
      const auto randNum = RAND_TABLE[i % NUM_RAND];
      std::swap(passengers[i], passengers[randNum % passengers.size()]);   
   }
}


// Prints out the boarding order 5 per line, displaying an asterisk next to 
// passengers with baggage.
void printBoardingOrder(const std::vector<Passenger*>& passengers) {
   std::cout << "Boarding order (* has carry-on):\n";
   auto count = 1;
   auto bagCount = 0;
   for(auto p : passengers) {
      std::cout << std::setw(3) << p->id() << (p->carryon() ? "* " : "  ");      
      if ((count % 5) == 0)
         std::cout << "\n";

      if (p->carryon())
         bagCount++;

      ++count;
   }
   std::cout << "\n";
   std::cout << "Passengers with bags: " << bagCount << " "
             << "out of " << passengers.size() << " total.\n";
   std::cout << "\n";
}


// Attempts to place a passenger's carryon, then seat the passengers returns false on failure.
bool boardPassengers(Airplane& airplane, const std::vector<Passenger*>& passengers) {
   bool halt = false;
   for (auto p : passengers) {
      if (!airplane.place_carryon(p)){
         std::cerr << "ERROR: bin full: "
                   << "   row  " << p->row() << "\n"  
                   << "   seat " << p->seat() << "\n";
         return false;  
      }

      if (!airplane.seat_passenger(p)){
         std::cerr << "ERROR: seat occupied: "
                   << "   row  " << p->row() << "\n"  
                   << "   seat " << p->seat() << "\n";
         return false;  
      }
   }

   std::cout << "\n";
   return true;
}


// Clean up by deleting all passengers allocated on the heap.
void deletePassengers(std::vector<Passenger*>& passengers) {
   for (auto & p: passengers)
      delete p;
}


// This is the meat of this project.
void runSimulation(int argc, char **argv) {
   // Get the variables from the user, display them.
   checkArgs(argc, argv);   
   int bag_chance, rows, width, passenger_count;
   parseArgs(argv, bag_chance, rows, width, passenger_count);
   outputArgs(bag_chance, rows, width, passenger_count);

   // Make, shuffle, print passengers.
   auto passengers = newPassengers(passenger_count, width, bag_chance);
   shufflePassengers(passengers);
   printBoardingOrder(passengers);

   // Make our plane, board it, print the results.
   Airplane plane(rows, width);
   const auto boarded = boardPassengers(plane, passengers); 
   plane.PrintSeats();
   plane.PrintOverheadBins();

   if (boarded)
      std::cout << "SUCCESS: all passengers boarded.\n\n";
   else
      std::cout << "FAILURE to board all passengers!\n\n";   

   // Clean up.
   deletePassengers(passengers);
}


// Hide the differences between compiling/running on IDEONE and locally.
// Uncomment this to run on IDEONE
// #define IDEONE
#if defined(IDEONE)
int main() {
   const auto argc = 5;
   const char* args[] = {
      "airplane", "4", "10", "4", "36"
   };
   char** argv = const_cast<char**>(&args[0]);
#else
int main(int argc, char** argv) {
#endif

   runSimulation(argc, argv);
   return 0;
}
