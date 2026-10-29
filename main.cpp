// Headers for data types, input/ output, and std namespace

// function to progress the cycle one stage
// function which reports for under/over feeding/shearing/milking within the map
// 3 helper functions for above which checks for miscar for an idividual sheep

// Declare map of array[3]s of lists of ints to hold data
// Read initial data from file into map
// Data in file will be formated as follows:
// initial days are all negtaive or 0, because they take place before the simulation begins
    // Sheep name
    // days eaten ie. -8, -7, -4, -3, -3
    // days sheared ie. -8, -4, 0
    // days milked ie. -7, -5, -3, -2, -1
    // repeate previous 4 lines for each sheep
// data read will be based on getline()

// decalare 3 functions which takes an array of 3 lists as input and returns an bool
// bool represents whether sheep should be sheared/milked/fed this day
// this functions should be as editable as possible, or have variables determined during runtime
// this function is what we can very between trials to try different feeding, shearing, and milking algorithsm
// the three functions each correspond to one of our 3 processes

// decalare a list of ints each for feeding, shearing, and milking
// each element in the list will represent a day, and the value
// shows if we over/under/correctly fed/sheared/milked the sheep, and by how much
// positive values for an excess of the process, negative for a shortage, and 0 for correct amount

// Main function
// loop to progress time
    // for each cycle:
        // run our fed, shear, and milk determining function for each sheep
        // add the current day to any sheep's list who undergoes the process
        // report any individual sheep who did not have their needs met
            // determined by const values. ie MAX_FEED_GAP = 2 determines the maxium
            // number of days a sheep can go without food without a shortage repeated
// Output total wasted time (food that was not eaten, over milking, over shearing)
// give a strong description of the results of our trial
// end of main function
