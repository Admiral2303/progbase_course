package event;

import com.thoughtworks.xstream.XStream;
import com.thoughtworks.xstream.io.xml.StaxDriver;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.*;

import static java.nio.file.StandardWatchEventKinds.*;

public class Main {

    public static void main(String[] args) {
        Config config = new Config();
        ScrumMaster master = new ScrumMaster();
        config = readConfig(config);
        master = readData(config, master);
        printData(master);
        try {
            WatchService watcher = FileSystems.getDefault().newWatchService();
            Path dir = Paths.get(System.getProperty("user.dir"));
            dir.register(watcher, ENTRY_CREATE, ENTRY_DELETE, ENTRY_MODIFY);

            while (true) {
                WatchKey key;
                try {
                    key = watcher.take();
                } catch (InterruptedException ex) {
                    return;
                }

                for (WatchEvent<?> event : key.pollEvents()) {
                    WatchEvent.Kind<?> kind = event.kind();

                    @SuppressWarnings("unchecked")
                    WatchEvent<Path> ev = (WatchEvent<Path>) event;
                    Path fileName = ev.context();

                    if (kind == ENTRY_MODIFY &&
                            fileName.toString().equals("configuration.xml")) {
                        System.out.println("Configuration file has changed!!!");
                        config = readConfig(config);
                        master = readData(config, master);
                        printData(master);
                    }
                    if(kind == ENTRY_MODIFY &&
                            fileName.toString().equals("master.xml")){
                        System.out.println("Data file has changed!!!");
                        master = readData(config, master);
                        printData(master);
                    }
                }
                boolean valid = key.reset();
                if (!valid) {
                    break;
                }
            }
        } catch (IOException ex) {
            System.err.println(ex);
        }

    }

    public static Config readConfig(Config config){
        XStream xs = new XStream(new StaxDriver());
        xs.alias("config", Config.class);
        try {
            FileInputStream fis1 = new FileInputStream("/home/vadim/Downloads/Event/configuration.xml");
            config = (Config) xs.fromXML(fis1);
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        }
        return config;
    }

    public static ScrumMaster readData(Config config, ScrumMaster master){
        XStream xs = new XStream(new StaxDriver());
        xs.alias("master", ScrumMaster.class);
        try {
            FileInputStream fis = new FileInputStream(config.getFilepath());
            master = (ScrumMaster) xs.fromXML(fis);
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        }
        return master;
    }

    public static void printData(ScrumMaster master){
        System.out.println("=============================");
        System.out.println(master.toString());
        System.out.println("=============================");
    }
}