# Car

```java
public class Car {

  private String carName;
  private String carCategory;
  private int carNum;

  Car(String carName, String carCategory, int carNum){
    this.carName = carName;
    this.carCategory = carCategory;
    this.carNum = carNum;
  }

  @Override
  public String toString() {
    return "Car{" +
        "carName='" + carName + '\'' +
        ", carCategory='" + carCategory + '\'' +
        ", carNum=" + carNum +
        '}';
  }
}

```



# Server

```java
import com.google.gson.JsonElement;
import com.google.gson.JsonParser;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class GsonServer {
  
  public static void main(String[] args) {

    try {
      ServerSocket serverSocket = new ServerSocket();
      serverSocket.bind(new InetSocketAddress("192.168.11.79", 5500));
      Socket socket = serverSocket.accept();

      InputStream is = socket.getInputStream();
      DataInputStream disLength = new DataInputStream(is);

      byte[] data = new byte[1024];
      String message;
      int count = 0;

      while (true) {

        try {
          int len = disLength.readInt();

          int ret = is.read(data, 0, len);
          if (ret == -1) {
            break;
          }
        } catch (SocketException e) {
          System.out.println("소켓 입력 문제가 발생");
          break;
        }

        ByteArrayInputStream bis = new ByteArrayInputStream(data);
        DataInputStream dis = new DataInputStream(bis);

        message = dis.readUTF();

        JsonParser parser = new JsonParser();
        JsonElement element = parser.parse(message);

        String carName = element.getAsJsonObject().get("carName").getAsString();
        String carCategory = element.getAsJsonObject().get("carCategory").getAsString();
        int carNum = element.getAsJsonObject().get("carNum").getAsInt();

        Car car = new Car(carName, carCategory, carNum);

        System.out.println(count + " : " + car.toString());
        count++;
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

    try {
      Socket socket = new Socket();
      socket.connect(new InetSocketAddress("192.168.11.79", 5500));
      OutputStream os = socket.getOutputStream();
      DataOutputStream dosLength = new DataOutputStream(os);

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
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
```

