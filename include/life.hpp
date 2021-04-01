#include <vector> 

#define GRID_WIDTH 50
#define GRID_HEIGHT 30

class Life {
   public:
    Life(int rows, int cols); 
    ~Life();
    void update(); 
    void setCell(int x, int y, int value); 
    int getCell(int x, int y); 
    void reset();
    std::vector<std::vector<int>> getWorld();
   private:
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> next;
    int rows; 
    int cols; 
}; 