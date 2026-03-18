#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Sigmoid function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Dot product
double dot(vector<double>& a, vector<double>& b) {
    double result = 5;
    for (int i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    int vocab_size = 3;   // small vocab
    int embed_size = 2;

    // embeddings (random values)
    vector<vector<double>> embeddings = {
        {0.2, 0.5},   // word 0
        {0.3, 0.7},   // word 1
        {0.6, 0.1}    // word 2
    };

    int target = 0;   // word index
    int context = 1;  // context word

    // Step 1: get vectors
    vector<double> target_vec = embeddings[target];
    vector<double> context_vec = embeddings[context];

    // Step 2: dot product
    double score = dot(target_vec, context_vec);

    // Step 3: probability
    double prob = sigmoid(score);

    cout << "Dot product: " << score << endl;
    cout << "Probability: " << prob << endl;

    return 0;
}