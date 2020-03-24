import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPClient {

	public static DatagramSocket clientSocket;
	public static DatagramPacket datagramPacket;
	public static BufferedReader bufferedReader;
	public static InetAddress inetAddress;
	public static byte buffer[] = new byte[35535];
	public static int cport = 222, sport = 6789;

	public static void main(String[] args) throws IOException {
		clientSocket = new DatagramSocket(cport);
		datagramPacket = new DatagramPacket(buffer, buffer.length);
		bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		inetAddress = InetAddress.getLocalHost();

		System.out.println("Client is Running...");
		System.out.println("Type some text OR if u want to Quit type 'exit' : ");
		
		while (true) {
			String str1 = new String(bufferedReader.readLine());
			buffer = str1.getBytes();
			if (str1.equals("exit")) {
				System.out.println("Terminated..");
				clientSocket.send(new DatagramPacket(buffer, str1.length(), inetAddress, sport));
				break;
			}
			clientSocket.send(new DatagramPacket(buffer, str1.length(), inetAddress, sport));

			clientSocket.receive(datagramPacket);
			String str4 = new String(datagramPacket.getData(), 0, datagramPacket.getLength());
			System.out.println("Server said : " + str4);
		}
	}
}
