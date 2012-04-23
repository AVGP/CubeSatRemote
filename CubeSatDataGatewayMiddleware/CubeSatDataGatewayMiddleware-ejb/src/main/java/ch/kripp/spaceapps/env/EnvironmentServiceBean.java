package ch.kripp.spaceapps.env;

import ch.kripp.spaceapps.domain.env.EnvironmentInfo;
import javax.ejb.Stateless;
import javax.ejb.LocalBean;
import javax.ejb.Remote;
import javax.inject.Named;

/**
 *
 * @author frank
 */
@Stateless
public class EnvironmentServiceBean {

    public EnvironmentInfo getEnvironmentIdentifier()
    {
        EnvironmentInfo result = new EnvironmentInfo();
        result.setEnvName("DEV");
               
        
        return result;
    }
    
}
