
void correlation_matrix::print_cluster(vector<node> &v, float _color,int count){
    vector<vector<bool> > temp_cluster(graph.size());
    for(int i=0;i<graph.size();i++)
    temp_cluster[i].resize(graph[i].size());

    //checking if not visited than mark it visited 
    for(int i=0;i<v.size();i++){
        if(!v[i].visited)
        {   count++;
            v[i].visited=true;
        }
    }

    for(int i=0;i<count;i++)
    {
        temp_cluster[rand()%temp_cluster.size()][rand()%temp_cluster[0].size()]=1;
    }

    ofstream file("txtFiles/"+to_string(count)+"cluster.txt");

    if(file.is_open()){
     
     for(int i=0;i<temp_cluster.size();i++){

        for(int j=0;j<temp_cluster[i].size();j++){
            //writing discrete values in file
            if(temp_cluster[i][j])
            file<<'1'<<',';
            else
            file<<'0'<<',';
        }
        file<<endl;
     }
        file.close();
    }
    else{
        cout<<"Error in opening cluster.txt\n";
    }
    if(_color)
    create_bitmap(to_string(count)+"cluster.txt",_color);
    else
    create_bitmap(to_string(count)+"cluster.txt");
}
void correlation_matrix::create_all_clusters_at_once(){

    // funciton to create all possible clusters at once 
    cout<<"all cluster at once\n";
    int _count=0;
    bool run=false;
    do{
        run=false;
    for(int i=0;i<bool_v.size();i++)
    { 
        if(bool_v[i])
        run=true;
    }
    if(run)
    create_cluster(++_count);
    }while(run);

}

void correlation_matrix::create_graph(){
graph.resize(permute_corr_matrix.size());

for(int i=0;i<graph.size();i++)
{
    graph[i].resize(permute_corr_matrix.size());
    for(int j=0;j<graph[0].size();j++)
    {
        //rejecting values below threshold
      if(graph[i][j].val<threshold)
      graph[i][j].val=10000;
    }
}


}
void correlation_matrix::create_cluster(int count){


for(int i=0;i<graph.size();i++)
{
    float sum;
    for(int j=0;j<graph[0].size();j++)
    {
    if(graph[i][j].val!=10000)
     sum+=graph[i][j].val;
    }
    node_weights.push_back(sum);
    bool_v.push_back(false);
}
//finding max
float max=INT8_MIN;
int max_index;
for(int i=0;i<node_weights.size();i++){

    if(node_weights[i]>max && !bool_v[i])
        {
            max=node_weights[i];
            max_index=i;
        }
}


print_cluster(graph[max_index],rand()%30+0.7,count);
bool_v[max_index]=true;
 

}
