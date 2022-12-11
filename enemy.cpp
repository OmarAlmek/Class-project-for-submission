#include "enemy.h"
#include <queue>

typedef tuple<double, int, int> Tuple;
Enemy1::Enemy1(int boardData[12][12])
{
    // Set Image
    QPixmap image("C:/Users/wifi/Downloads/en1.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 10;
    column = 6;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set health
    health = 2;
}
void Enemy1::movingenemy(Pair& source, Pair destination)
{
    auto i = bfs(source, destination, data);
    this->row = i.first;
    this->column = i.second;
    this->setPos(50 + 50 *column, 50 + 50* row);
}
void Enemy1::losehealth(){
    health--;
}
int Enemy1::gethealth(){
    return health;
}
void Enemy1::sethealth(int h){
    health = h;
}
void Enemy1::set_row(int r){
    row=r;
}
void Enemy1::set_column(int c){
    column=c;
}
void Enemy1::reset_health(){
    health=2;
}
Pair Enemy1::find(Pair src, Pair des, vector <vector <Pair>> parent) {
    auto par = parent[des.first][des.second] ;
    if (par ==src ) return des;
    return find(src, par, parent);
}

Pair Enemy1::bfs(Pair source, Pair des, int matrix[12][12]) {
    int n =12 , m = 12;
    queue <pair <pair <int ,int >, int >>  q;
    vector <vector <pair<int,int >>> parent (n, vector<Pair>(m,{0,0}) );
    vector <vector <int >> dis(n, vector <int > (m,1e9));
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    q.push({source,0});
    dis[source.first][source.second] = 0;
    while(!q.empty()){
        auto x = q.front().first.first;
        int y = q.front().first.second;
        auto distance = q.front().second;
        q.pop();
        for (int i =0;i<4;i++){
            int newx = x+ dx[i];
            int newy = y + dy[i];
            if (newx <0 || newy <0 || newx>=n || newy>=m) continue;
            if (matrix[newx][newy]==-1 || dis[newx][newy]<=distance+1) continue;
            dis[newx][newy]= distance+1;
            parent[newx][newy] = {x,y};
            q.push({{newx,newy},distance+1});
        }
    }
    pair <int ,int > ans = find(source, des, parent  );
    return ans;
}
void Enemy1::hurt(){
    QPixmap image("C:/Users/wifi/Downloads/enhurt.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
}
