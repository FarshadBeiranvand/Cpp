#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a structure for forces
struct Force {
    double magnitude;
    double angle; // Angle in degrees with respect to the positive x-axis
};

// Define a structure for supports
struct Support {
    double x_reaction;
    double y_reaction;
    double moment_reaction;
};

// Function prototypes
void solveStatics();
vector<Force> inputForces(int num_forces);
vector<double> inputMoments(int num_moments);
Support calculateSupportReactions(const vector<Force>& forces, const vector<double>& moments);
void outputResults(const Support& support);
void visualizeStructure(const vector<Force>& forces, const vector<double>& moments, const Support& support);

int main() {
    // Hi there! Welcome to the Statics Solver!
    cout << "Welcome to the Statics Solver!" << endl;
    // Alright, let's solve some statics problems!
    solveStatics();
    // See ya later, Statics Solver! It's been real!
    cout << "Exiting Statics Solver. Goodbye!" << endl;
    return 0;
}

// Function to handle the solving of statics problems
void solveStatics() {
    int num_forces, num_moments;
    vector<Force> forces;
    vector<double> moments;
    Support support;

    // Yo, how many forces are we dealing with here?
    cout << "Enter the number of forces acting on the structure: ";
    cin >> num_forces;

    // Gimme those forces, buddy!
    forces = inputForces(num_forces);

    // Alright, now how many moments are in the mix?
    cout << "Enter the number of moments acting on the structure: ";
    cin >> num_moments;

    // Sweet, let's hear about those moments!
    moments = inputMoments(num_moments);

    // Let's crunch some numbers and figure out those support reactions!
    support = calculateSupportReactions(forces, moments);

    // Boom! Here are the support reactions!
    outputResults(support);

    // Let's visualize this baby! Show me what you got!
    visualizeStructure(forces, moments, support);
}

// Function to input forces from the user
vector<Force> inputForces(int num_forces) {
    vector<Force> forces;
    for (int i = 0; i < num_forces; ++i) {
        Force f;
        // Alright, what's the deal with this force? Tell me everything!
        cout << "Enter the magnitude of force " << i + 1 << " (in Newtons): ";
        cin >> f.magnitude;
        // And what angle is this force coming from?
        cout << "Enter the angle of force " << i + 1 << " (in degrees, relative to the positive x-axis): ";
        cin >> f.angle;
        // Alright, got it. Adding that force to the mix!
        forces.push_back(f);
    }
    return forces;
}

// Function to input moments from the user
vector<double> inputMoments(int num_moments) {
    vector<double> moments;
    for (int i = 0; i < num_moments; ++i) {
        double moment;
        // So, what's the scoop on this moment? Lay it on me!
        cout << "Enter the magnitude of moment " << i + 1 << " (in Newton-meters): ";
        cin >> moment;
        // Alright, adding that moment to the list!
        moments.push_back(moment);
    }
    return moments;
}

// Function to calculate support reactions
Support calculateSupportReactions(const vector<Force>& forces, const vector<double>& moments) {
    Support support;
    // Let's crunch some numbers and figure out those support reactions!
    // For now, let's keep it simple and assume fixed support.
    support.x_reaction = 0;
    support.y_reaction = 0;
    support.moment_reaction = 0;
    return support;
}

// Function to output support reactions
void outputResults(const Support& support) {
    // Alright, here are the support reactions!
    cout << "\nSupport reactions:" << endl;
    cout << "X-reaction: " << support.x_reaction << " Newtons" << endl;
    cout << "Y-reaction: " << support.y_reaction << " Newtons" << endl;
    cout << "Moment reaction: " << support.moment_reaction << " Newton-meters" << endl;
}

// Function to visualize the structure and force/moment distribution
void visualizeStructure(const vector<Force>& forces, const vector<double>& moments, const Support& support) {
    // Alright, let's take a look at the structure and how these forces and moments are playing out!
    cout << "\nVisualization of the structure:" << endl;
    // Placeholder for visualization
    // (We'll make it look pretty later!)
}
