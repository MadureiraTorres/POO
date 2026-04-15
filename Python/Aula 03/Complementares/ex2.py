class Sensor:
    contador = 0

    def __init__(self, id_sensor):
        self.id_sensor = id_sensor
        Sensor.contador += 1
        print(f"Sensor {self.id_sensor} criado. Total de instâncias: {Sensor.contador}")

    def __del__(self):
        Sensor.contador -= 1
        print(f"Sensor {self.id_sensor} destruído. Total de instâncias: {Sensor.contador}")

def escopo_interno():
    s2 = Sensor(2)
    s3 = Sensor(3)
    print("Saindo do escopo interno...")

if __name__ == "__main__":
    s1 = Sensor(1)
    escopo_interno()
    print("Fim da execução principal.")