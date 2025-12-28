#ifndef WebServerModule_H
#define WebServerModule_H

#include <Arduino.h>
#include <Update.h>
#include <WiFi.h>
#include <WebServer.h>
#include "config/config.h"
#include "webServer/wifiUpdate/htmlPages/mainPage.h"
#include "webServer/wifiUpdate/htmlPages/uploadPage.h"

class WebServerModule {
    public:
        WebServerModule();
        void begin();  // Inicializa WiFi e servidor
        void handleClient();  // Processa pedidos
        
    private:
        WebServer server;
        bool apMode;
        
        void wifiConfig();
        void accessPointConfig();
        void serverConfig();
        
        // Métodos para callbacks (têm acesso aos membros da classe)
        void handleRoot();
        void handleUpdate();
        void handleUpdateEnd();
        
        // Funções auxiliares
        String getUpTime();
        String getIP();
        
        // Funções estáticas para callbacks do WebServer
        static void handleRootStatic();
        static void handleUpdateStatic();
        static void handleUpdateEndStatic();
        
        // Ponteiro estático para a instância atual
        static WebServerModule* instance;
};

#endif