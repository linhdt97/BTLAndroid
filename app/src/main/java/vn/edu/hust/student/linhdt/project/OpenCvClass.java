package vn.edu.hust.student.linhdt.project;

/**
 * Created by DELL on 5/22/2018.
 */

public class OpenCvClass {
    public native static void catDetection(long addrRgba);
    public native static void dogDetection(long addrRgba);
    public native static void buffaloDetection(long addrRgba);
    public native static void peopleDetection(long addrRgba);
    public native static void pigDetection(long addrRgba);
    public native static void chickenDetection(long addrRgba);
}
