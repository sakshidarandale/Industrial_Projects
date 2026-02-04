//Final Unpacking Code

import java.io.*;
import java.util.*;

class UnpackerX
{

     public int FileSize = 0;
     public int i = 0;
     public int iRet = 0;

     public byte Key = 0x11;

     public Scanner sobj = null;

     public String FileName = null;
     public String Header = null;
     public String Tokens[] = null;

     public File fpackobj = null;
     public File fobj = null;

     public FileInputStream fiobj = null;
     public FileOutputStream foobj = null;

     public byte bHeader[] = new byte[100];
     public byte Buffer[] = null;

     public UnpackerX()
     {
          FileSize = 0;
          i = 0;
          iRet = 0;

          Key = 0x11;

          sobj = null;

          FileName = null;
          Header = null;
          Tokens = null;

          fpackobj = null;
          fobj = null;

          fiobj = null;
          foobj = null;

          bHeader = new byte[100];
          Buffer = null;
     }

     public void unpack()
     {
          sobj = new  Scanner(System.in);

          System.out.println("Enter the name of packed file : ");
          FileName = sobj.nextLine();

          fpackobj = new File(FileName);

          try
          {
               if(fpackobj.exists() == false)
               {
                    System.out.println("Error : There is no such packed file");

                    return;
               }

               fiobj = new FileInputStream(fpackobj);

               //Read the Header

               while((iRet =fiobj.read(bHeader,0,100)) != -1)
               {
               

                    Header = new String(bHeader);

                    Header = Header.trim();

                    Tokens = Header.split(" ");

                    System.out.println("File name :" +Tokens[0]);
                    System.out.println("File size :" +Tokens[1]);

                    fobj = new File(Tokens[0]);

                    fobj.createNewFile();

                    foobj = new FileOutputStream(fobj);

                    FileSize = Integer.parseInt(Tokens[1]);

                    //Buffer for reading the data
                    Buffer = new byte[FileSize];

                    //Read from packed file 
                    fiobj.read(Buffer,0,FileSize);

                    //Decrpyt the data

                    for(i = 0; i < FileSize; i++)
                    {
                         Buffer[i] =(byte)(Buffer[i] ^ Key);
                    }

                    //Write into extracted file
                    foobj.write(Buffer,0,FileSize);

               }
          }

          catch(Exception eobj)
          {
               System.out.println("Error : " +eobj.getMessage());
          }
     }   
}
       
class Unpacker
{
     public static void main(String A[])
     {
          UnpackerX uobj = new UnpackerX();

          uobj.unpack();
     }
}

