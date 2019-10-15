void utf8substr(std::string originalString, int SubStrLength, std::string& csSubstring)
{
    size_t len = 0;
    int byteIndex =0;
    const unsigned char* aStr = (unsigned char *)originalString.c_str();
    size_t origSize = originalString.size();

    int i ;
    for (len = 0; len < origSize; )
    {
         if(byteIndex >= SubStrLength)
            break;
        
         if ((aStr[len] >= 0xc2) && (aStr[len] <= 0xdf )) {
            i = 2;           
         } else if ((aStr[len] >= 0xe0) && (aStr[len] <= 0xef)) {
            i = 3;
         } else if ((aStr[len] >= 0xf0) && (aStr[len] <= 0xf7)) {
            i = 4;
         } else if ((aStr[len] >= 0xf8) && (aStr[len] <= 0xfb)) {
            i = 5;
         } else if ((aStr[len] >= 0xfc) && (aStr[len] <= 0xfd)) {
            i = 6;
        }else {             
            i = 1;     
        }         
        len += i;
        byteIndex++;
        cout << "i =" << i <<  " byteIndex="  << byteIndex  << endl;
    }

    
    csSubstring = originalString.substr(0, len);
}
