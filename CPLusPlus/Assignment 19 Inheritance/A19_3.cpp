#include<iostream>
#include<string.h>
using namespace std;

/*
A19.3 Define a class Actor with name, age as instance variables and setter,
getters as instance methods. Define a class TVActor as a derived class of
Actor with instance variable to store number of TV projects done or 
running and define setter, getter. Also define setTVActor() and ShowTVActor().
Define a class MovieActor as a derived class of Actor with instance variable
to store number of movies done or running and define setter, getter. Also 
define setMovieActor() and showMovieActor(). Derive a class AllScreenActor
from TVActor and MovieActor. Define a method to setActorData() and 
showActorData().
(Completed)
*/
class Actor
{
    private:
        char name[100];
        int age;
    public:
        void setName(const char *name) { strcpy(this->name, name); }
        void setAge(int age) { this->age = age; }
        char* getName() { return name; }
        int getAge() { return age; }
};
class TVActor: virtual public Actor
{
    private:
        int TVProjectsDone, TVProjectsRunning;
    public:
        void setTVProjectsDone(int TVProjectsDone) { this->TVProjectsDone = TVProjectsDone; }
        void setTVProjectsRunning(int TVProjectsRunning) { this->TVProjectsRunning = TVProjectsRunning; }
        int getTVProjectsDone() { return TVProjectsDone; }
        int getTVProjectsRunning() { return TVProjectsRunning; }
        void setTVActor(const char* name, int age, int TVProjectsDone, int TVProjectsRunning)
        {
            setName(name);
            setAge(age);
            this->TVProjectsDone = TVProjectsDone;
            this->TVProjectsRunning = TVProjectsRunning;
        }
        void showTVActor()
        {
            cout<<"TV Actor Details:"<<endl;
            cout<<"Name: "<<getName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"TV Projects Done: "<<TVProjectsDone<<endl;
            cout<<"TV Projects Running: "<<TVProjectsRunning<<endl;
        }
};
class MovieActor: virtual public Actor
{
    private:
        int MovieProjectsDone, MovieProjectsRunning;
    public:
        void setMovieProjectsDone(int MovieProjectsDone) { this->MovieProjectsDone = MovieProjectsDone; }
        void setMovieProjectsRunning(int MovieProjectsRunning) { this->MovieProjectsRunning = MovieProjectsRunning; }
        int getMovieProjectsDone() { return MovieProjectsDone; }
        int getMovieProjectsRunning() { return MovieProjectsRunning; }
        void setMovieActor(const char *name, int age, int MovieProjectsDone, int MovieProjectsRunning)
        {
            setName(name);
            setAge(age);
            this->MovieProjectsDone = MovieProjectsDone;
            this->MovieProjectsRunning = MovieProjectsRunning;
        }
        void showMovieActor()
        {
            cout<<"Movie Actor Details:"<<endl;
            cout<<"Name: "<<getName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"Movie Projects Done: "<<MovieProjectsDone<<endl;
            cout<<"Movie Projects Running: "<<MovieProjectsRunning<<endl;
        }
};
class AllScreenActor: public TVActor, public MovieActor
{
    public:
        void setActorData(const char *name, int age, int TVProjectsDone, int TVProjectsRunning, int MovieProjectsDone, int MovieProjectsRunning)
        {
            setName(name);
            setAge(age);
            setTVProjectsDone(TVProjectsDone);
            setTVProjectsRunning(TVProjectsRunning);
            setMovieProjectsDone(MovieProjectsDone);
            setMovieProjectsRunning(MovieProjectsRunning);   
        }
        void showActorData()
        {
            cout<<"AllScreen Actor Details:"<<endl;
            cout<<"Name: "<<getName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"TV Projects Done: "<<getTVProjectsDone()<<endl;
            cout<<"TV Projects Running: "<<getTVProjectsRunning()<<endl;
            cout<<"Movie Projects Done: "<<getMovieProjectsDone()<<endl;
            cout<<"Movie Projects Running: "<<getMovieProjectsRunning()<<endl;
        }
};


int main()
{
    AllScreenActor Amitabh;
    Amitabh.setActorData("Amitabh Bachchan", 72, 12, 1, 140, 2);
    Amitabh.showActorData();
    return 0;
}