#include <iostream>


class CameraConfig {
private:
     int num_modes;
    int* resolution_width;
    int* resolution_height;

public:
    // Constructor
   CameraConfig(int n,int widths[],int heights[])
   :num_modes(n){
       resolution_width=new int[num_modes];
       resolution_height=new int[num_modes];
       for(int i=0;i<num_modes;++i){
           resolution_width[i]=widths[i];
           resolution_height[i]=heights[i];
       }
   }
   //copy constructor
   CameraConfig(const CameraConfig& other)
   :num_modes(other.num_modes){
       resolution_width=new int[num_modes];
       resolution_height=new int[num_modes];
       for(int i=0;i<num_modes;++i){
           resolution_width[i]=other.resolution_width[i];
           resolution_height[i]=other.resolution_height[i];
       }
   }
   ~CameraConfig(){
       delete[] resolution_width;
       delete[] resolution_height;
   }
   void printConfig() const{
       for(int i=0;i<num_modes;++i){
           std::cout<<"Mode"<<i<<":"
           <<resolution_width[i]<<"x"
           <<resolution_height[i]<< std::endl;
       }
       
   }
   bool isHigherResolution(int mode1,int mode2) const{
       int res1=this->resolution_width[mode1]*this->resolution_height[mode1];
       int res2=this->resolution_width[mode2]*this->resolution_height[mode2];
       return res1>res2;
   }
};
   
   // Global Functions
   void printCameraConfig(const CameraConfig& config){
       config.printConfig();
       
   }
   bool globalCompareResolution(const CameraConfig& config,int m1,int m2){
       return config.isHigherResolution(m1,m2);
       
   }


//main function
int main(){
    int num_modes=3;
    int widths[3]={8909,1890,1889};
    int heights[3]={7099,9897,1098};
    
    CameraConfig camConfig(num_modes,widths,heights);
    
    std::cout << "Camera Configurations:" << std::endl;
    printCameraConfig(camConfig);
    
    if(camConfig.isHigherResolution(0,2)){
        std::cout <<"Mode 0 has higher resolution than mode 2(member function)." << std::endl;
        }else{
            std::cout <<"Mode 2 has higher resolution than mode 0(member function)." << std::endl;
        }
        if(globalCompareResolution(camConfig,0,2)){
            std::cout <<"Mode 0 has higher resolution than mode 2(global function)." << std::endl;
        }else{
            std::cout <<"Mode 2 has higher resolution than mode 0(global function)." << std::endl;
        }

    return 0;
}
