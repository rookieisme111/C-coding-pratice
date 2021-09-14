class Singleton{
private:
    Singleton(){
        pthread_mutex_init(&mutex);
    }
private:
    static Singleton* instance;
    static pthread_mutex_t mutex;

public:
    Singleton* getInstance(){
        if (instance==nullptr){
            pthread_mutex_lock(&mutex);
            if (instance==nullptr){
                instance = new Singleton();
            }
            pthread_mutex_lock(&mutex);
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;