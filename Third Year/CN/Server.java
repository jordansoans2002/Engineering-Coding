import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
    ServerSocket server;
    Socket connection;
    ObjectOutputStream output;
    ObjectInputStream input;
    Scanner sc;
    FileInputStream inputFile;

    public static void main(String []args){
        Server ob=new Server();
        try {
            try {
                ob.makeConnection();
                ob.setupStreams();
                ob.chat();
            } catch (EOFException e) {
                System.out.println("connection closed");
            } finally {
                ob.closeChat();
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    public void makeConnection() throws IOException {
        server=new ServerSocket(5555);
        connection=server.accept();
    }

    public void setupStreams() throws IOException{
        output=new ObjectOutputStream(connection.getOutputStream());
        output.flush();

        input=new ObjectInputStream(connection.getInputStream());
    }

    public void chat() throws IOException{
        sc=new Scanner(System.in);
        String out="",in="";
        System.out.println("you can now chat");
        System.out.println("enter \"END\" to close chat");
        do{
            out=sc.nextLine();
            output.writeObject(out);
            System.out.println("SENT "+out);

            try {
                in = input.readObject().toString();
                System.out.println("Received "+in);
            }catch (ClassNotFoundException e){
                System.out.println("invalid message");
            }
        }while(!in.equals("END")|| !out.equals("END"));
    }

    public void closeChat(){
        try {
            if (input != null)
                input.close();
            if (output != null)
                output.close();
            if (connection != null)
                connection.close();
            if (server != null)
                server.close();
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}