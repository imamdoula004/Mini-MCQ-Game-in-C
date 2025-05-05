#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 30

// Function declarations
void printQuestion(int qIndex);
void checkAnswer(int qIndex, int userAnswer, int *score);
void shuffleQuestions(int *order);

char *generalKnowledgeQuestions[MAX_QUESTIONS] = {
    "What is the capital of France?",
    "Who wrote 'Romeo and Juliet'?",
    "What is the largest planet in our solar system?",
    "What is the chemical symbol for water?",
    "Who painted the 'Mona Lisa'?",
    "What is the longest river in the world?",
    "Who is known as the 'Father of Computers'?",
    "In which country was the game of chess invented?",
    "What is the tallest mountain in the world?",
    "Which planet is known as the Red Planet?",
    "What is the chemical symbol for water?",
    "Which gas do plants absorb from the atmosphere during photosynthesis?",
    "What is the speed of light in a vacuum?",
    "What does RAM stand for in Technology?",
    "Which company created the C programming language?",
    "What is 15 * 6?",
    "What is the value of pi to two decimal places?",
    "What is the square root of 144?",
    "Who was the first President of the United States?",
    "In which year did World War II end?",
    "Who is known as the 'King of Pop'?",
    "Which country has the most population in the world?",
    "What is the smallest country in the world by area?",
    "What is 7 * 8?",
    "If a triangle has angles of 90 degrees and 45 degrees, what is the third angle?",
    "What is 2^3? (2 raised to the power of 3)",
    "Which movie features the character 'Tony Stark'?",
    "Who sang the song 'Shape of You'?",
    "What is the name of the fictional wizarding school in the Harry Potter series?",
    "Which superhero is known as the 'Dark Knight'?"
};

char *generalKnowledgeOptions[MAX_QUESTIONS][4] = {
    {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"},
    {"1. William Shakespeare", "2. Charles Dickens", "3. Mark Twain", "4. Jane Austen"},
    {"1. Earth", "2. Mars", "3. Jupiter", "4. Saturn"},
    {"1. O2", "2. CO2", "3. H2O", "4. N2"},
    {"1. Pablo Picasso", "2. Leonardo da Vinci", "3. Vincent van Gogh", "4. Michelangelo"},
    {"1. Amazon River", "2. Nile River", "3. Yangtze River", "4. Mississippi River"},
    {"1. Alan Turing", "2. Charles Babbage", "3. Bill Gates", "4. Steve Jobs"},
    {"1. China", "2. India", "3. Iran", "4. Russia"},
    {"1. Mount Kilimanjaro", "2. Mount Everest", "3. Mount Fuji", "4. Mount McKinley"},
    {"1. Venus", "2. Mars", "3. Earth", "4. Neptune"},
    {"1. O2", "2. H2O", "3. CO2", "4. NaCl"},
    {"1. Oxygen", "2. Carbon Dioxide", "3. Nitrogen", "4. Hydrogen"},
    {"1. 300,000 km/s", "2. 150,000 km/s", "3. 450,000 km/s", "4. 600,000 km/s"},
    {"1. Random Access Memory", "2. Read-Only Memory", "3. Run Access Memory", "4. Random Assign Memory"},
    {"1. Microsoft", "2. Bell Labs", "3. Google", "4. IBM"},
    {"1. 90", "2. 85", "3. 80", "4. 95"},
    {"1. 3.12", "2. 3.14", "3. 3.15", "4. 3.16"},
    {"1. 10", "2. 11", "3. 12", "4. 13"},
    {"1. George Washington", "2. Abraham Lincoln", "3. Thomas Jefferson", "4. John Adams"},
    {"1. 1944", "2. 1945", "3. 1946", "4. 1947"},
    {"1. Elvis Presley", "2. Michael Jackson", "3. Prince", "4. Freddie Mercury"},
    {"1. United States", "2. India", "3. China", "4. Indonesia"},
    {"1. Monaco", "2. Vatican City", "3. Malta", "3. San Marino"},
    {"1. 48", "2. 56", "3. 64", "4. 72"},
    {"1. 30 degrees", "2. 45 degrees", "3. 60 degrees", "4. 90 degrees"},
    {"1. 6", "2. 8", "3. 9", "4. 12"},
    {"1. Batman", "2. Superman", "3. Iron Man", "4. Spider-Man"},
    {"1. Ed Sheeran", "2. Bruno Mars", "3. Justin Bieber", "4. Shawn Mendes"},
    {"1. Beauxbatons Academy", "2. Durmstrang Institute", "3. Ilvermorny School", "4. Hogwarts School of Witchcraft and Wizardry"},
    {"1. Superman", "2. Iron Man", "3. Batman", "4. Spider-Man"}
};

int generalKnowledgeAnswers[MAX_QUESTIONS] = {3, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 3, 1, 2, 2, 3, 2, 2, 2, 2, 3, 1, 4, 3};

int main() {
    int order[MAX_QUESTIONS], userAnswer, score = 0, numQuestions;

    // Initialize random number generator
    srand(time(NULL));

    // Prompt user for the number of questions until valid input is provided
    do {
        printf("Welcome to the General Knowledge Quiz!\n");
        printf("Please type in the number of questions you would like to answer (1-%d):\n", MAX_QUESTIONS);
        if (scanf("%d", &numQuestions) != 1) {
            // Invalid input (not an integer)
            printf("Invalid input! Please enter an integer.\n");

            // Clear the input buffer
            while (getchar() != '\n');
            numQuestions = -1; // Set to invalid value to stay in the loop
        } else if (numQuestions < 1 || numQuestions > MAX_QUESTIONS) {
            // Input out of range
            printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_QUESTIONS);
        }
    } while (numQuestions < 1 || numQuestions > MAX_QUESTIONS);

    printf("You chose to play with %d questions.\n\n", numQuestions);

    // Shuffle questions for random order
    shuffleQuestions(order);

    // Game loop for the specified number of questions
    for (int i = 0; i < numQuestions; i++) {
        int qIndex = order[i];
        printQuestion(qIndex);
        printf("Your answer:\n");
        scanf("%d", &userAnswer);

        checkAnswer(qIndex, userAnswer, &score);

        printf("\nYour current score is: %d/%d\n\n", score, i + 1);
    }

    // Final score
    printf("Game Over! Your final score is: %d/%d\n", score, numQuestions);
    return 0;
}

// Function to print the question and choices
void printQuestion(int qIndex) {
    printf("%s\n", generalKnowledgeQuestions[qIndex]);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", generalKnowledgeOptions[qIndex][i]);
    }
}

// Function to check the user's answer
void checkAnswer(int qIndex, int userAnswer, int *score) {
    if (userAnswer == generalKnowledgeAnswers[qIndex]) {
        printf("Correct!\n");
        (*score)++;
    } else {
        printf("Incorrect. The correct answer is option %d.\n", generalKnowledgeAnswers[qIndex]);
    }
}

// Function to shuffle the questions order
void shuffleQuestions(int *order) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        order[i] = i;
    }

    // Shuffle the order array using Fisher-Yates shuffle algorithm
    for (int i = MAX_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
}
