#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
};
struct Playlist 
{
    struct Song* head;
};
void addSong(struct Playlist* playlist, const char* title, const char* artist) 
{
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = playlist->head;
    playlist->head = newSong;
}
void removeSong(struct Playlist* playlist, const char* title) 
{
    struct Song* temp = playlist->head;
    struct Song* prev = NULL;
    while (temp != NULL && strcmp(temp->title, title) != 0) 
	{
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
	   return;
    if (prev == NULL) 
	{
        playlist->head = temp->next;
    } 
	else 
	{
        prev->next = temp->next;
    }
    free(temp);
}
void displayPlaylist(struct Playlist* playlist) 
    {
    struct Song* current = playlist->head;
    if (current == NULL) 
	{
        printf("Playlist is empty\n");
        return;
    }
    while (current != NULL) 
	{
        printf("Title: %s, Artist: %s\n", current->title, current->artist);
        current = current->next;
    }
}
int main() {
    struct Playlist playlist;
    playlist.head = NULL;
    int choice;
    char title[100], artist[100];
    while (1) {
        printf("1. Add Song\n2. Remove Song\n3. Display Playlist\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter song title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            printf("Enter artist name: ");
            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = '\0';
            addSong(&playlist, title, artist);
        } 
		else if (choice == 2) 
		{
            printf("Enter song title to remove: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            removeSong(&playlist, title);
        } 
		else if (choice == 3)
		{
            displayPlaylist(&playlist);
        } 
		else if (choice == 4) 
		{
            break;
        } 
		else 
		{
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

