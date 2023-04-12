import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    Socket connection;
    ObjectOutputStream output;
    ObjectInputStream input;

    FileOutputStream outputFile;

    public static void main(String []args){
        Client ob=new Client();
        try {
            try {
                ob.makeConnection();
                ob.setupStreams();
                ob.chatting();
            } catch (EOFException e) {
                System.out.println("Connection closed");
            } finally {
                ob.closeChat();
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    void makeConnection()throws IOException{
        connection=new Socket("127.0.0.1",5555);
    }

    void setupStreams() throws IOException{
        output=new ObjectOutputStream(connection.getOutputStream());
        output.flush();

        input=new ObjectInputStream(connection.getInputStream());

        outputFile=new FileOutputStream("text.txt");
    }

    void chatting() throws IOException{
        Scanner sc=new Scanner(System.in);
        String in="",out="";
        System.out.println("you can now chat");
        do{
            try{
                in=input.readObject().toString();
                System.out.println("RECEIVED "+in);
            }catch(ClassNotFoundException e){
                System.out.println("invalid message");
            }

            out=sc.nextLine();
            output.writeObject(out);
            System.out.println("SENT "+out);

            // outputFile.write();
        }while(!in.equals("END")|| !out.equals("END"));
    }

    void closeChat(){
        try {
            if (input != null)
                input.close();
            if (output != null)
                output.close();
            if (connection != null)
                connection.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}