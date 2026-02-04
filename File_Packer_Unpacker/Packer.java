//Packing Code

import java.io.*;
import java.util.*;

class PackerX
{
    
    public int iRet;
    public int i,j;

    public byte Key;

    public Scanner sobj;

    public String FolderName;
    public String PackName;
    public String Header;

    public File fobj;
    public File Packobj;

    public FileOutputStream foobj;
    public FileInputStream fiobj;
    
    public byte Buffer[];
    public byte bHeader[];

    public PackerX()
    {
        iRet = 0;
        i = 0; 
        j = 0;

        Key = 0x11;

        Scanner sobj = null;

        FolderName = null;
        PackName = null;
        Header = null;

        fobj = null;
        Packobj = null;

        foobj = null;
        fiobj = null;
        
        Buffer= new byte[1024];
        bHeader= new byte[100];

    }

    public void pack()
    {
        sobj = new Scanner(System.in);

        System.out.println("Enter the name of folder : ");
        FolderName = sobj.nextLine();

        System.out.println("Enter the name of packed file : ");
        PackName = sobj.nextLine();

        fobj = new File(FolderName);

        try
        {
            if(fobj.exists() && (fobj.isDirectory()))
            {
                Packobj = new File(PackName);

                Packobj.createNewFile();

                foobj= new FileOutputStream(Packobj);

                System.out.println("Folder is present");

                File fArr[] = fobj.listFiles();

                System.out.println("Number of files in the folder are : " +fArr.length);

                for(i = 0; i<fArr.length ; i++)
                {
                    fiobj = new FileInputStream(fArr[i]);

                if(fArr[i].getName().endsWith(".txt"))  
                {

                        //Header Formation

                        Header = fArr[i].getName() + " "  + fArr[i].length();

                        for(j =Header.length(); j < 100 ; j++)
                        {
                            Header = Header + " ";
                        }

                        bHeader = Header.getBytes();

                        //Write Header into Pack File
                        foobj.write(bHeader,0,100);

                        //Read the data from input files from Marvellous Folder

                        while((iRet = fiobj.read(Buffer)) != -1)
                        {
                            //Encryption logic

                            for(j = 0 ; j < iRet ; j++)
                            {
                                Buffer[j] = (byte) (Buffer[j] ^ Key);
                            }

                            //Write the files data into Pack File
                            foobj.write(Buffer,0 ,iRet);
                        }
                }
                fiobj.close();
                }
                foobj.close();
            }
            else
            {
                System.out.println("There is no such folder");
            }

            sobj.close();
        }

        catch(Exception eobj)
        {
            System.out.println("Error : " + eobj.getMessage());
        }
    }     
}

class Packer
{
    public static void main(String A[])
    {
        PackerX pobj = new PackerX();
        pobj.pack();
    }

}
