// M.Raahim 24k-0543 
// Assignment 3 q7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define MAX_CATEGORIES 5
#define MAX_DEVICES 3
#define MAX_CONTENT 10
struct Content {
    char title[50];
    float rating;
    int runtime;
    char encoding[20];
};
struct UserProfile {
    char username[30];
    double *engagementScores;
    double **devicePreferences;
};
struct Category {
    struct Content *contents[MAX_CONTENT];
};
void initializeUserProfiles(struct UserProfile users[], int numUsers);
void initializeEngagementScores(struct UserProfile *user);
void initializeDevicePreferences(struct UserProfile *user);
void addEngagementScore(struct UserProfile *user, int categoryIndex, double score);
void displayUserEngagement(const struct UserProfile *user);
void initializeCategories(struct Category categories[]);
void addContentToCategory(struct Category *category, int contentIndex, const char *title, float rating, int runtime, const char *encoding);
void displayCategoryContents(const struct Category *category);

int main() {
    struct UserProfile users[MAX_USERS];
    struct Category categories[MAX_CATEGORIES];
    initializeUserProfiles(users, MAX_USERS);
    initializeCategories(categories);
    addContentToCategory(&categories[0], 0, "Action Movie 1", 8.5, 120, "H.264");
    addContentToCategory(&categories[1], 0, "Drama Movie 1", 7.8, 90, "H.265");
    addEngagementScore(&users[0], 0, 5.0);
    addEngagementScore(&users[0], 1, 3.5);
    printf("Engagement Scores for %s:\n", users[0].username);
    displayUserEngagement(&users[0]);
    printf("\nContents of Action Category:\n");
    displayCategoryContents(&categories[0]);
    return 0;
}
void initializeUserProfiles(struct UserProfile users[], int numUsers) {
	int i;
    for (i = 0; i < numUsers; i++) {
        snprintf(users[i].username, sizeof(users[i].username), "User%d", i + 1);
        users[i].engagementScores = (double *)malloc(MAX_CATEGORIES * sizeof(double));
        memset(users[i].engagementScores, 0, MAX_CATEGORIES * sizeof(double));
        initializeDevicePreferences(&users[i]);
    }
}
void initializeDevicePreferences(struct UserProfile *user) {
    user->devicePreferences = (double **)malloc(MAX_DEVICES * sizeof(double*));
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {    
		user->devicePreferences[i] = (double *)malloc(3 * sizeof(double));
        memset(user->devicePreferences[i], 0, 3 * sizeof(double));
    }
}
void addEngagementScore(struct UserProfile *user, int categoryIndex, double score) {
    if (categoryIndex >= 0 && categoryIndex < MAX_CATEGORIES) {
        user->engagementScores[categoryIndex] += score;
    }
}
void displayUserEngagement(const struct UserProfile *user) {
    int i;
	for ( i = 0; i < MAX_CATEGORIES; i++) {
        printf("Category %d Engagement Score: %.2f\n", i + 1, user->engagementScores[i]);
    }
}
void initializeCategories(struct Category categories[]) {
    int i,j;
	for ( i = 0; i < MAX_CATEGORIES; i++) {
        for (j = 0; j < MAX_CONTENT; j++) {
            categories[i].contents[j] = NULL;
        }
    }
}
void addContentToCategory(struct Category *category, int contentIndex, const char *title, float rating, int runtime, const char *encoding) {
    if (contentIndex >= 0 && contentIndex < MAX_CONTENT) {
        category->contents[contentIndex] = (struct Content *)malloc(sizeof(struct Content));
        strncpy(category->contents[contentIndex]->title, title, sizeof(category->contents[contentIndex]->title));
        category->contents[contentIndex]->rating = rating;
        category->contents[contentIndex]->runtime = runtime;
        strncpy(category->contents[contentIndex]->encoding, encoding, sizeof(category->contents[contentIndex]->encoding));
    }
}
void displayCategoryContents(const struct Category *category) {
    int i;
	for (i = 0; i < MAX_CONTENT; i++) {
        if (category->contents[i] != NULL) {
            printf("Title: %s \nRating: %.1f \nRuntime: %d mins \nEncoding: %s\n",
                   category->contents[i]->title,
                   category->contents[i]->rating,
                   category->contents[i]->runtime,
                   category->contents[i]->encoding);
        }
    }
}
