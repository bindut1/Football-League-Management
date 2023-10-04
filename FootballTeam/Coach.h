#include "Human.h"

class Coach : public Human
{
    private:
        string idHLV;
    public:
        Coach(string = "", string = "", string = "", string = "", int = 0, string = "");
        ~Coach();
        void show();
};