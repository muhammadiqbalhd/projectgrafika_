#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float rotationAngle = 0.0f;

void drawBedFrame() {
    // Menggambar bingkai tempat tidur
    glPushMatrix(); // Simpan matriks saat ini
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Rotasi sekitar sumbu Y

    glBegin(GL_QUADS);

    // Atas tempat tidur
    glColor3f(0.5f, 0.35f, 0.05f); // Warna coklat
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);

    // Kaki tempat tidur
    glColor3f(0.5f, 0.35f, 0.05f); // Warna coklat
    glVertex3f(-0.7f, 0.0f, -0.3f);
    glVertex3f(-0.7f, -1.0f, -0.3f);
    glVertex3f(-0.6f, -1.0f, -0.3f);
    glVertex3f(-0.6f, 0.0f, -0.3f);

    glVertex3f(0.7f, 0.0f, -0.3f);
    glVertex3f(0.7f, -1.0f, -0.3f);
    glVertex3f(0.6f, -1.0f, -0.3f);
    glVertex3f(0.6f, 0.0f, -0.3f);

    // Belakang kepala tempat tidur
    glColor3f(0.5f, 0.35f, 0.05f); // Warna coklat
    glVertex3f(-0.8f, 0.0f, 1.0f);
    glVertex3f(0.8f, 0.0f, 1.0f);
    glVertex3f(0.8f, -1.0f, 1.0f);
    glVertex3f(-0.8f, -1.0f, 1.0f);

    glEnd();

    glPopMatrix(); // Pulihkan matriks sebelumnya setelah rotasi
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Panggil fungsi untuk menggambar bingkai tempat tidur
    drawBedFrame();

    glFlush();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        rotationAngle += 10.0f; // Putar ke kiri sebesar 10 derajat
    }
    else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        rotationAngle -= 10.0f; // Putar ke kanan sebesar 10 derajat
    }
}

int main() {
    // Inisialisasi GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Buat jendela GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Tempat Tidur OpenGL 3D", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Inisialisasi GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    // Set warna background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna background putih

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Set callback keyboard
    glfwSetKeyCallback(window, keyCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render
        render();

        // Swap buffers
        glfwSwapBuffers(window);

        // Handle events
        glfwPollEvents();
    }

    // Clean up
    glfwTerminate();

    return 0;
}
