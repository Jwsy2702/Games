#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

int xytoi(int x, int y, int rowlen);
bool merge_num(std::vector<int>& v, int bi, int ei);
void rotate_anti_clock(std::vector<int>& v);
bool game_over(const std::vector<int>& v);
void print_grid(const std::vector<int>& v);

int main(){
  std::ifstream infile;
  std::string filename;
  std::vector<int> vin, vout;

  std::cout << "please enter the name of the file of value inputs" << std::endl;
  std::cin >> filename;

  infile.open(filename.c_str());

  if (!infile.is_open()){
    std::cout <<"file not found, using default start configuration" <<std::endl;

    for(int i=0; i<15; i++){
      vin.push_back(0);
    }

    vin.push_back(2);
  }

  int n;

  while (infile >> n){
    vin.push_back(n);
  } //will this be ignored if line 24-30 executes?

  print_grid(vin);

  bool gameover = game_over(vin);
  std::string input;
  int side = std::sqrt(vin.size());
  bool mergenum = false;

  while (gameover == false){
    std::cin >> input;
    std::cout << std::endl;
    if(input == "a"){
      mergenum = false;

      for(int i=0; i < side; i++){
          std::vector<int> vtmp;

          for(int j=0; j < side; j++){
            vtmp.push_back(vin[xytoi(i, j, side)]);
          }

          if(merge_num(vtmp, 0, side-1) == true){
            mergenum = true;
          }

          for(int k=0; k < side; k++){
            vout.push_back(vtmp[k]);
          }

          vtmp.erase(vtmp.begin(), vtmp.begin()+vtmp.size());
      }

      if(mergenum == true){
        vin = vout;

        while(vout == vin){
          int r = rand() % vin.size();

          if (vin[r]==0){
            vin[r] = 2;
          }
        }
        print_grid(vin);
      }

      vout.erase(vout.begin(), vout.begin()+vout.size());

      gameover = game_over(vin);

      if(gameover == true){
        std::cout << "game over" << std::endl;
        return 0;
      }

    }

    else if(input == "w"){
      rotate_anti_clock(vin);

      mergenum = false;

      for(int i=0; i < side; i++){
          std::vector<int> vtmp;

          for(int j=0; j < side; j++){
            vtmp.push_back(vin[xytoi(i, j, side)]);
          }

          if(merge_num(vtmp, 0, side-1) == true){
            mergenum = true;
          }

          for(int k=0; k < side; k++){
            vout.push_back(vtmp[k]);
          }

          vtmp.erase(vtmp.begin(), vtmp.begin()+vtmp.size());
      }

      if(mergenum == true){
        vin = vout;

        while(vout == vin){
          int r = rand() % vin.size();

          if (vin[r]==0){
            vin[r] = 2;
          }
        }
        rotate_anti_clock(vin);
        rotate_anti_clock(vin);
        rotate_anti_clock(vin);
        print_grid(vin);
      }
      else{
        rotate_anti_clock(vin);
        rotate_anti_clock(vin);
        rotate_anti_clock(vin);
      }

      vout.erase(vout.begin(), vout.begin()+vout.size());

      gameover = game_over(vin);

      if(gameover == true){
        std::cout << "game over" << std::endl;
        return 0;
      }

    }


    else if(input == "s"){
      rotate_anti_clock(vin);
      rotate_anti_clock(vin);
      rotate_anti_clock(vin);

      mergenum = false;

      for(int i=0; i < side; i++){
          std::vector<int> vtmp;

          for(int j=0; j < side; j++){
            vtmp.push_back(vin[xytoi(i, j, side)]);
          }

          if(merge_num(vtmp, 0, side-1) == true){
            mergenum = true;
          }

          for(int k=0; k < side; k++){
            vout.push_back(vtmp[k]);
          }

          vtmp.erase(vtmp.begin(), vtmp.begin()+vtmp.size());
      }

      if(mergenum == true){
        vin = vout;

        while(vout == vin){
          int r = rand() % vin.size();

          if (vin[r]==0){
            vin[r] = 2;
          }
        }
        rotate_anti_clock(vin);
        print_grid(vin);
      }

      else{
        rotate_anti_clock(vin);
      }

      vout.erase(vout.begin(), vout.begin()+vout.size());

      gameover = game_over(vin);

      if(gameover == true){
        std::cout << "game over" << std::endl;
        return 0;
      }
    }

    else if(input == "d"){
      rotate_anti_clock(vin);
      rotate_anti_clock(vin);

      mergenum = false;

      for(int i=0; i < side; i++){
          std::vector<int> vtmp;

          for(int j=0; j < side; j++){
            vtmp.push_back(vin[xytoi(i, j, side)]);
          }

          if(merge_num(vtmp, 0, side-1) == true){
            mergenum = true;
          }

          for(int k=0; k < side; k++){
            vout.push_back(vtmp[k]);
          }

          vtmp.erase(vtmp.begin(), vtmp.begin()+vtmp.size());
      }

      if(mergenum == true){
        vin = vout;

        while(vout == vin){
          int r = rand() % vin.size();

          if (vin[r]==0){
            vin[r] = 2;
          }
        }
        rotate_anti_clock(vin);
        rotate_anti_clock(vin);
        print_grid(vin);
      }
      else{
        rotate_anti_clock(vin);
        rotate_anti_clock(vin);
      }

      vout.erase(vout.begin(), vout.begin()+vout.size());


      gameover = game_over(vin);

      if(gameover == true){
        std::cout << "game over" << std::endl;
        return 0;
      }
    }
  }


  std::cout << "game over" << std::endl;

  return 0;
}

void rotate_anti_clock(std::vector<int>& v){
  std::vector<int> vtmp;
  int n = std::sqrt(v.size());
  for(int j = n-1; j >= 0; j--){
      for(int i = 0; i < n; i++){
        vtmp.push_back(v[xytoi(i, j, n)]);
      }
  }
  v = vtmp;
}

void print_grid(const std::vector<int>& v){
  int side = std::sqrt(v.size());
  for(int i=0; i<side; i++){
    for(int j=0; j<side; j++){
      std::cout << v[xytoi(i, j, side)] << "\t";
    }
    std::cout << std::endl;
  }
}

int xytoi(int x, int y, int rowlen){
    return x*rowlen + y;
}


bool merge_num(std::vector<int>& v, int bi, int ei){
  std::vector<int> tmp, tmp2;
  tmp2 = v;
  v = tmp;
  tmp = tmp2; //working with tmp

  for (int i=0; i < bi; i++){
    v.push_back(tmp[i]);
  } //first i to bi-1 terms
  int j = 0;
  int i = bi;
  int one;
  int two;
  while (i <= ei){

    //search for nonzero
    while(tmp[i]==0 && i <= ei){
      i++;
      j++;
    }
    //at this point, in[i] is nonzeros
    if(j == ei-bi+1){
      for(int i = bi; i <= ei; i++){
        v.push_back(0);
      }
      for(int i = ei+1; i < tmp.size(); i++){
        v.push_back(tmp[i]);
      }
      return false;
    } //account for all zeros case

    if(i<=ei){
      one=tmp[i];
    }
    else{
      one=tmp[i-1];
    } //case where 2 numbers merge, the rest are zeros. e.g. 4 4 0 0
    // i=4, j=1 here

    i++;
    //search for second nonzero
    while(tmp[i]==0 && i <= ei){
      i++;
      j++;
    }
    //at this point, in[i] is nonzero
    two = tmp[i];
    if(one == two){
      v.push_back(one*2);
      i++;
      j++;
    }
    else{
      v.push_back(one);
    }

  }

  for (int i=0; i < j; i++){
    v.push_back(0);
  } //putting the rest of the zeros back

  for (int i=ei+1; i < tmp.size(); i++){
    v.push_back(tmp[i]);
  } //putting back ei+1 to end of vector terms


  for(int i=0; i < tmp.size(); i++){
    if (tmp[i] != v[i]){
      return true;
    }
  }
  return false;
}

bool game_over(const std::vector<int>& v){
  int side = std::sqrt(v.size());
  std::vector<int> tmp;

  tmp = v;

  for (int i=0; i<tmp.size(); i++){
    if (tmp[i]==0){
      return false;
    }
  }
  for (int i=0; i < side; i++){
    for(int j=0; j < side - 1; j++){
      if (tmp[xytoi(i, j, side)] == tmp[xytoi(i, j, side) + 1]){
        return false;
      }
    }
  }

  rotate_anti_clock(tmp);

  for (int i=0; i<tmp.size(); i++){
    if (tmp[i]==0){
      return false;
    }
  }
  for (int i=0; i < side; i++){
    for(int j=0; j < side - 1; j++){
      if (tmp[xytoi(i, j, side)] == tmp[xytoi(i, j, side) + 1]){
        return false;
      }
    }
  }

  return true;
}
