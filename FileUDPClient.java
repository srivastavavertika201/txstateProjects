import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class FileUDPClient {

	public static DatagramSocket clientsocket;
	public static DatagramPacket datagramPacket;
	public static BufferedReader bufferedReader;
	public static InetAddress inetAddress;
	public static byte buffer[] = new byte[35535];
	public static int clientPort = 222, serverSocket = 6789;

	public static void main(String[] args) throws IOException {
		clientsocket = new DatagramSocket(clientPort); 
		datagramPacket = new DatagramPacket(buffer, buffer.length);
		bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		inetAddress = InetAddress.getLocalHost();
 
		System.out.println("Client is Running...");
		System.out.println("Type file name OR if u want to Quit type 'exit' : ");
		while (true) {
			String str1 = new String(bufferedReader.readLine());
			buffer = str1.getBytes();
			if (str1.equals("exit")) {
				System.out.println("Terminated.."); 
				clientsocket.send(new DatagramPacket(buffer, str1.length(), inetAddress, serverSocket));
				break;
			}
			clientsocket.send(new DatagramPacket(buffer, str1.length(), inetAddress, serverSocket));
 
			clientsocket.receive(datagramPacket);
			String str4 = new String(datagramPacket.getData(), 0, datagramPacket.getLength());
			System.out.println("Server response : " + str4);
		}
	}

}
