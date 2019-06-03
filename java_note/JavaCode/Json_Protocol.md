# Car

```java
public class Car {

  private String name;
  private String category;
  private int num;

  Car(String name, String category, int num){
    this.name = name;
    this.category = category;
    this.num = num;
  }

  @Override
  public String toString() {
    return "Car{" +
        "name='" + name + '\'' +
        ", category='" + category + '\'' +
        ", num=" + num +
        '}';
  }
}

```



# Server

```java
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class GsonServer {

  public static void main(String[] args) {

    try (ServerSocket serverSocket = new ServerSocket()) {
      serverSocket.bind(new InetSocketAddress("192.168.11.79", 5500));
      Socket socket = serverSocket.accept();

      try (InputStream is = socket.getInputStream();
          DataInputStream disLength = new DataInputStream(is)) {

        byte[] data = new byte[1024];
        String jsonToString;
        int count = 0;

        while (true) {

          try {
            int len = disLength.readInt();

            int ret = is.read(data, 0, len);
            if (ret == -1) {
              break;
            }
          } catch (EOFException e){
            e.printStackTrace();
            break;
          }

          try (ByteArrayInputStream bis = new ByteArrayInputStream(data);
              DataInputStream dis = new DataInputStream(bis)) {

            jsonToString = dis.readUTF();
            Gson gson = new GsonBuilder().setPrettyPrinting().create();

            System.out.println(count + " : " + gson.fromJson(jsonToString, Car.class));
            count++;
          } catch (EOFException e){
            e.printStackTrace();
          }
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}

```

# Client

```java
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;

public class GsonClient {

  public static void main(String[] args) {

    Car car = new Car("dreamCar", "sportCar", 7777);

    try (Socket socket = new Socket()) {
      socket.connect(new InetSocketAddress("192.168.11.79", 5500));

      try (OutputStream os = socket.getOutputStream();
          DataOutputStream dosLength = new DataOutputStream(os)) {

        Gson prettyGson = new GsonBuilder().setPrettyPrinting().create();
        //Gson basicGson = new Gson();

        String prettyJson = prettyGson.toJson(car);
        //String basicJson = basicGson.toJson(car);

        for (int i = 0; i < 100; i++) {

          ByteArrayOutputStream bos = new ByteArrayOutputStream();
          DataOutputStream dos = new DataOutputStream(bos);

          dos.writeUTF(prettyJson);

          byte[] buf = bos.toByteArray();
          int len = bos.size();

          dosLength.writeInt(len);
          os.write(buf, 0, len);
        }
      } catch (IOException e){
        e.printStackTrace();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}

```

