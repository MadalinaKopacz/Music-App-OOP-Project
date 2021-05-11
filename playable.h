#ifndef PLAYABLE_H_INCLUDED
#define PLAYABLE_H_INCLUDED

class Like
{
public:
 virtual void Liked() = 0;
 virtual void Disliked() = 0;
};

class LikePodcast : public Like
{
public:
    void Liked()
    {
        cout<<"Ai dat like acestui podcast.\n";
    }
    void Disliked()
    {
        cout<<"Ai dat dislike acestui podcast.\n";
    }
};

class LikeMelody : public Like
{
public:
    void Liked()
    {
        cout<<"Ai dat like acestei melodii.\n";
    }
    void Disliked()
    {
        cout<<"Ai dat dislike acestei melodii.\n";
    }
};

#endif // PLAYABLE_H_INCLUDED
